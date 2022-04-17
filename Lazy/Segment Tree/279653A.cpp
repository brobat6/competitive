#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

template <typename T>
class SegTree {
public:
    vector <T> tree;
    vector <T> lazy;

    SegTree(int size) {
        tree.resize(size);
        lazy.resize(size);
    }

    void push(int node) {
        tree[node * 2] += lazy[node];
        tree[node * 2 + 1] += lazy[node];
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
        lazy[node] = 0;
    }

    void update_range(int node, int start, int end, int l, int r, T val) {
        // Add val to [l, r].
        if(start == end) {
            tree[node] += val;
            lazy[node] = 0;
            return;
        }
        if(l == start && r == end) {
            tree[node] += val;
            lazy[node] += val;
        } else {
            push(node);
            int mid = (start + end)/2;
            if(l <= mid) update_range(node * 2, start, mid, l, min(r, mid), val);
            if(r > mid) update_range(node * 2 + 1, mid + 1, end, max(l, mid + 1), r, val);
            tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    T query(int node, int start, int end, int l, int r) {
        if(start == end) {
            return tree[node];
        }
        if(l == start && r == end) {
            return tree[node];
        }
        push(node);
        int mid = (start + end)/2;
        int a = 1E18, b = 1E18;
        if(l <= mid) a = query(node * 2, start, mid, l, min(r, mid));
        if(r > mid) b = query(node * 2 + 1, mid + 1, end, max(l, mid + 1), r);
        return min(a, b);
    }
};

void solve() {

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    SegTree<int> st(4*n);
    for(int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a;
        if(a == 1) {
            cin >> b >> c >> d;
            st.update_range(1, 0, n - 1, b, c - 1, d);
        } else {
            cin >> b >> c;
            cout << st.query(1, 0, n - 1, b, c - 1) << "\n";
        }
    }
    
    return 0;
}