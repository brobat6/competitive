#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

template <typename T>
class SegTree {
public:
    vector <T> tree;

    SegTree(int size) {
        tree.resize(size);
    }

    void update_range(int node, int start, int end, int l, int r, T val) {
        // Add val to [l, r].
        if(l == start && r == end) {
            tree[node] = max(tree[node], val);
        } else {
            int mid = (start + end)/2;
            if(l <= mid) update_range(node * 2, start, mid, l, min(r, mid), val);
            if(r > mid) update_range(node * 2 + 1, mid + 1, end, max(l, mid + 1), r, val);
        }
    }

    T query(int node, int start, int end, int pos) {
        if(start == end) {
            return tree[node];
        }
        int mid = (start + end)/2;
        if(pos <= mid) {
            return max(tree[node], query(node * 2, start, mid, pos));
        } else {
            return max(tree[node], query(node * 2 + 1, mid + 1, end, pos));
        }
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
            cin >> b;
            cout << st.query(1, 0, n - 1, b) << "\n";
        }
    }
    
    return 0;
}