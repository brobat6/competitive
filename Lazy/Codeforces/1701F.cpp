#include <bits/stdc++.h>
using namespace std;
#define int long long

#define pi pair<int, int>
#define tii tuple<int, int, int>
#define F first
#define S second

class SegTree {
    int n;
    vector <int> cnt, sz, lazy, x, y;
    // x --> sum, y --> sum of squares

public:
    SegTree(int _n) : n(_n) {
        cnt.resize(n<<2, 0);
        sz.resize(n<<2, 0);
        tree.resize(n<<2, {0, 0});
        lazy.resize(n<<2, {0, 0});
        build(1, 0, n - 1);
    }

    void build(int node, int start, int end) {
        sz[node] = end - start + 1;
        if(start != end) {
            int mid = (start + end)>>1;
            build(node<<1, start, mid);
            build(node<<1|1, mid + 1, end);
        }
    }

    void push(int node) {
        for(int i = 0; i < 2; i++) {
            // tree[node<<1|i].S += (lazy[node].)
        }
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    
    return 0;
}