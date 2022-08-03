#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
class SegTree {
public:
    int n;
    vector <T> t;

    T id = 0; // identity element, set it

    T comb(T a, T b) { // how to combine values, set it
        return a + b;
    }

    SegTree(int _n) : n(_n) {
        t.resize(2*n, id);
    }

    SegTree(vector <T> &v) {
        n = v.size();
        t.resize(2*n, id);
        build(v);
    }

    void build(vector <T> &v) {
        for(int i = n; i < 2*n; i++) t[i] = v[i - n];
        for(int i = n - 1; i > 0; i--) t[i] = comb(t[i<<1], t[i<<1 | 1]);
    }

    void update(int p, T value) { // set value at position p
        for(t[p += n] = value; p > 1; p >>= 1) {
            t[p >> 1] = comb(t[p], t[p ^ 1]);
        }
    }

    T query(int l, int r) { // query on interval [l, r)
        T res = id;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) res = comb(res, t[l++]);
            if(r & 1) res = comb(res, t[--r]);
        }
        return res;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    
    return 0;
}