#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define pi pair<int, int>

const int INF = 1E18;

pi calc(pi &a, pi &b) {
    return {max(a.first, b.first), min(a.second, b.second)};
}

pi find(int a, int b) {
    if(a == b) return {0, INF};
    if(a < b) {
        return {0, (a + b)/2};
    } else {
        return {(a + b + 1)/2, INF};
    }
}

class SegTree {
public:
    vector <pi> tree;
    vector <pi> range;
    vector <int> v;

    SegTree(int size, vector <int> &ss) {
        tree.resize(size);
        range.resize(size);
        v = ss;
    }

    pi func(int left, int right) {
        pi a = tree[left];
        pi b = tree[right];
        pi c = find(v[range[left].second], v[range[right].first]);
        pi d = calc(a, b);
        return calc(d, c);
    }

    void build(int node, int start, int end) {
        range[node] = {start, end};
        if(start == end) {
            tree[node] = {0, INF};
        } else {
            int mid = (start + end)/2;
            build(2*node, start, mid);
            build(2*node + 1, mid + 1, end);
            tree[node] = func(node*2, node*2 + 1);
        }
    }

    void update(int node, int start, int end, int pos, int val) {
        if(start == end) {
            v[start] = val;
            tree[node] = {0, INF};
        } else {
            int mid = (start + end)/2;
            if(pos <= mid) {
                update(node*2, start, mid, pos, val);
            } else {
                update(node*2 + 1, mid + 1, end, pos, val);
            }
            tree[node] = func(node*2, node*2 + 1);
        }
    }

    pi query(int node, int start, int end, int l, int r) {
        if(l == start && r == end) {
            return tree[node];
        }
        int mid = (start + end)/2;
        pi a = {0, INF + 1};
        pi b = {0, INF + 1};
        if(l <= mid) a = query(node*2, start, mid, l, min(mid, r));
        if(r > mid) b = query(node*2 + 1, mid + 1, end, max(l, mid + 1), r);
        if(a.second == INF + 1) return b;
        if(b.second == INF + 1) return a;
        pi c = find(v[mid], v[mid + 1]);
        pi d = calc(a, b);
        return calc(c, d);
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    SegTree st(4*n, v);
    st.build(1, 0, n - 1);
    for(int i = 0; i < q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) {
            st.update(1, 0, n - 1, b - 1, c);
        } else {
            pi x = st.query(1, 0, n - 1, b - 1, c - 1);
            if(x.first <= x.second) cout << x.first << endl;
            else cout << -1 << endl;
        }
    }
    
    return 0;
}