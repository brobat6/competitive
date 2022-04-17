#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int LOW = -1E18;

/*
1 2 3 -10^18 60 50 60 -10^18 3 2 1
*/


class SegTree {
public:
    struct Data {
        int sum, pref, suff, ans;
    };
    vector <Data> tree;
    vector <int> lazy;
    vector <int> sz;
    vector <bool> marked;

    SegTree(int size) {
        tree.resize(size);
        lazy.resize(size);
        sz.resize(size);
        marked.resize(size, false);
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

    void default_node(int node, int val) {
        tree[node].sum = val;
        if(val < 0) tree[node].pref = tree[node].suff = tree[node].ans = 0;
        else tree[node].pref = tree[node].suff = tree[node].ans = val;
    }

    void push(int node) {
        default_node(node * 2, lazy[node] * sz[node * 2]);
        default_node(node * 2 + 1, lazy[node] * sz[node * 2 + 1]);
        lazy[node * 2] = lazy[node];
        lazy[node * 2 + 1] = lazy[node];
        marked[node*2] = true;
        marked[node*2 + 1] = true;
        marked[node] = false;
    }

    Data combine(Data l, Data r) {
        Data res;
        res.sum = l.sum + r.sum;
        res.pref = max(l.pref, l.sum + r.pref);
        res.suff = max(r.suff, r.sum + l.suff);
        res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
        return res;
    }

    void update_range(int node, int start, int end, int l, int r, int val) {
        if(start == end) {
            default_node(node, val);
            marked[node] = false;
            return;
        }
        if(l == start && r == end) {
            default_node(node, val * sz[node]);
            lazy[node] = val;
            marked[node] = true;
        } else {
            int mid = (start + end)/2;
            if(marked[node]) push(node);
            if(l <= mid) update_range(node * 2, start, mid, l, min(r, mid), val);
            if(r > mid) update_range(node * 2 + 1, mid + 1, end, max(l, mid + 1), r, val);
            tree[node] = combine(tree[node * 2], tree[node * 2 + 1]);
        }
    }

    Data query(int node, int start, int end, int l, int r) {
        if(l == start && r == end) {
            return tree[node];
        }
        if(marked[node]) push(node);
        int mid = (start + end)/2;
        Data a{0, LOW, LOW, LOW};
        Data b{0, LOW, LOW, LOW};
        if(l <= mid) a = query(node * 2, start, mid, l, min(r, mid));
        if(r > mid) b = query(node * 2 + 1, mid + 1, end, max(l, mid + 1), r);
        return combine(a, b);
    }
};

void solve() {

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    SegTree st(4*n);
    st.build(1, 0, n - 1);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        st.update_range(1, 0, n - 1, a, b - 1, c);
        cout << st.query(1, 0, n - 1, 0, n - 1).ans << endl;
    }
    
    return 0;
}