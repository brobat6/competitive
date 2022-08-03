#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
 
template <typename T>
class SegTree {
public:
    vector <T> tree;
    vector <T> lazy;
    vector <bool> marked;
    vector <int> sz;
 
    SegTree(int size) {
        tree.resize(size);
        lazy.resize(size);
        marked.resize(size, false);
        sz.resize(size);
    }
 
    void build(int node, int start, int end) {
        if(start == end) {
            sz[node] = 1;
        } else {
            int mid = (start + end)/2;
            build(node*2, start, mid);
            build(node*2 + 1, mid + 1, end);
            sz[node] = end - start + 1;
        }
    }
 
    void push(int node) {
        tree[node*2] = (lazy[node] * sz[node * 2]);
        tree[node*2 + 1] = (lazy[node] * sz[node * 2 + 1]);
        lazy[node*2] = lazy[node];
        lazy[node*2 + 1] = lazy[node];
        marked[node*2] = true;
        marked[node*2 + 1] = true;
        marked[node] = false;
    }
 
    void update_range(int node, int start, int end, int l, int r, T val) {
        // Add val to [l, r].
        if(start == end) {
            tree[node] = val;
            marked[node] = false;
            return;
        }
        if(l == start && r == end) {
            tree[node] = val * (end - start + 1);
            lazy[node] = val;
            marked[node] = true;
        } else {
            if(marked[node]) push(node);
            int mid = (start + end)/2;
            if(l <= mid) update_range(node * 2, start, mid, l, min(r, mid), val);
            if(r > mid) update_range(node * 2 + 1, mid + 1, end, max(l, mid + 1), r, val);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }
 
    T query(int node, int start, int end, int l, int r) {
        if(l == start && r == end) {
            return tree[node];
        }
        if(marked[node]) push(node);
        int mid = (start + end)/2;
        int a = 0, b = 0;
        if(l <= mid) a = query(node * 2, start, mid, l, min(r, mid));
        if(r > mid) b = query(node * 2 + 1, mid + 1, end, max(l, mid + 1), r);
        return a + b;
    }
};