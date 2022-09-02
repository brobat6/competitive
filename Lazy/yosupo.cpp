#include <bits/stdc++.h>
using namespace std;
#define int long long

class SegTree {
public:
    vector <int> st, sz;

    SegTree(int n) {
        st.resize(4*n, 0);
        sz.resize(4*n, 1);
    }

    void pull(int node) {
        st[node] = st[node<<1] + st[node<<1|1];
    }

    void build(int node, int start, int end, vector <int> &v) {
        if(start == end) {
            st[node] = v[start];
        } else {
            int mid = (start + end)/2;
            build(node<<1, start, mid, v);
            build(node<<1|1, mid + 1, end, v);
            pull(node);
            sz[node] = sz[node<<1] + sz[node<<1|1];
        }
    }

    void update(int node, int start, int end, int pos, int add) {
        if(start == end) {
            st[node] += add;
        } else {
            int mid = (start + end)/2;
            if(pos <= mid) update(node<<1, start, mid, pos, add);
            else update(node<<1|1, mid+1, end, pos, add);
            pull(node);
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if(start == end) return st[node];
        if(l == start && r == end) return st[node];
        int mid = (start + end)/2;
        int x = 0;
        if(l <= mid) x += query(node*2, start, mid, l, min(r, mid));
        if(r > mid) x += query(node*2 + 1, mid+1, end, max(l, mid + 1), r);
        return x; 
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    SegTree st(n);
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    st.build(1, 0, n - 1, v);
    for(int i = 0; i < q; i++) {
        int type, a, b;
        cin >> type >> a >> b;
        if(type == 1) {
            cout << st.query(1, 0, n - 1, a, b - 1) << '\n';
        } else {
            st.update(1, 0, n - 1, a, b);
        }
    }
    
    return 0;
}