#include <bits/stdc++.h>
using namespace std;

// Source: Me
// Tested on: CF 1641 C
// Simple to use lazy segtree
// Change comb, push, E and ID based on problem.
template <class T>
struct LazySegTree {
  int n;
  vector<T> t, lz;
  T E = 0;   // Identity element for segtree data
  T ID = 0;  // Identity element for lazy update

  T comb(T a, T b) {  // Segtree function
    return a + b;
  }
  void push(int node, int l, int r) {  // Propagation
    t[node] += (r - l + 1) * lz[node];
    if (l != r) {  // Propagate
      for (int it = 0; it < 2; it++) lz[2 * node + it] += lz[node];
    }
    lz[node] = ID;
  }
  LazySegTree() {}
  LazySegTree(int _n) : n(_n) {
    t.assign(4 * n + 5, E);
    lz.assign(4 * n + 5, ID);
  }
  LazySegTree(vector<T>& bld)
      : n(bld.size()), t(4 * n + 5, E), lz(4 * n + 5, ID) {
    t.assign(4 * n + 5, E);
    lz.assign(4 * n + 5, ID);
    build(bld, 1, 0, n - 1);
  }
  void build(vector<T>& bld, int node, int tl, int tr) {
    if (tl == tr) {
      t[node] = bld[tl];
    } else {
      int tm = (tl + tr) / 2;
      build(bld, 2 * node, tl, tm);
      build(bld, 2 * node + 1, tm + 1, tr);
      pull(node);
    }
  }
  void pull(int node) { t[node] = comb(t[2 * node], t[2 * node + 1]); }

  void apply(int l, int r, T val) { apply(l, r, val, 1, 0, n - 1); }
  void apply(int l, int r, T val, int node, int tl, int tr) {
    push(node, tl, tr);
    if (r < tl || tr < l) return;
    if (l <= tl && tr <= r) {
      lz[node] = val;
      push(node, tl, tr);
      return;
    }
    int tm = (tl + tr) / 2;
    apply(l, r, val, 2 * node, tl, tm);
    apply(l, r, val, 2 * node + 1, tm + 1, tr);
    pull(node);
  }

  T query(int l, int r) { return query(l, r, 1, 0, n - 1); }
  T query(int l, int r, int node, int tl, int tr) {
    push(node, tl, tr);
    if (r < tl || tr < l) return E;
    if (l <= tl && tr <= r) return t[node];
    int tm = (tl + tr) / 2;
    return comb(query(l, r, 2 * node, tl, tm),
                query(l, r, 2 * node + 1, tm + 1, tr));
  }

  // first index such that f(index) is true
  int search_first(int l, int r, const function<bool(T)>& f) {
    return search_first(l, r, f, 1, 0, n - 1);
  }
  int search_first_knowingly(const function<bool(T)>& f, int node, int tl,
                             int tr) {
    push(node, tl, tr);
    if (tl == tr) return tl;
    int tm = (tl + tr) / 2;
    int res;
    if (f(t[2 * node]))
      res = search_first_knowingly(f, 2 * node, tl, tm);
    else
      res = search_first_knowingly(f, 2 * node + 1, tm + 1, tr);
    pull(node);
    return res;
  }
  int search_first(int l, int r, const function<bool(T)>& f, int node, int tl,
                   int tr) {
    push(node, tl, tr);
    if (l <= tl && tr <= r) {
      if (!f(t[node])) return -1;
      return search_first_knowingly(f, node, tl, tr);
    }
    int tm = (tl + tr) / 2;
    int res = -1;
    if (l <= tm) res = search_first(l, r, f, 2 * node, tl, tm);
    if (r > tm && res == -1)
      res = search_first(l, r, f, 2 * node + 1, tm + 1, tr);
    pull(node);
    return res;
  }

  // last index such that f(index) is true
  int search_last(int l, int r, const function<bool(T)>& f) {
    return search_last(l, r, f, 1, 0, n - 1);
  }
  int search_last_knowingly(const function<bool(T)>& f, int node, int tl,
                            int tr) {
    push(node, tl, tr);
    if (tl == tr) return tl;
    int tm = (tl + tr) / 2;
    int res;
    if (f(t[2 * node + 1]))
      res = search_last_knowingly(f, 2 * node + 1, tm + 1, tr);
    else
      res = search_last_knowingly(f, 2 * node, tl, tm);
    pull(node);
    return res;
  }
  int search_last(int l, int r, const function<bool(T)>& f, int node, int tl,
                  int tr) {
    push(node, tl, tr);
    if (l <= tl && tr <= r) {
      if (!f(t[node])) return -1;
      return search_last_knowingly(f, node, tl, tr);
    }
    int tm = (tl + tr) / 2;
    int res = -1;
    if (r > tm) res = search_last(l, r, f, 2 * node + 1, tm + 1, tr);
    if (l <= tm && res == -1) res = search_last(l, r, f, 2 * node, tl, tm);
    pull(node);
    return res;
  }
};