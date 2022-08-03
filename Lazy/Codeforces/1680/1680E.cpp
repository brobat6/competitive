#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
class SegTree {
public:
    vector <T> tree;

    SegTree(int size) {
        tree.resize(size, 0);
    }

    T func(T a, T b) {
        return a + b; // Segment tree for the sum
        // return min(a, b); // Segment tree for the minimum
    }

    void build(int node, int start, int end, vector <T> &v) {
        if(start == end) {
            tree[node] = v[start];
        } else {
            int mid = (start + end)/2;
            build(2*node, start, mid, v);
            build(2*node + 1, mid + 1, end, v);
            tree[node] = func(tree[node*2], tree[node*2 + 1]);
        }
    }

    void update(int node, int start, int end, int pos, T val) {
        if(start == end) {
            tree[node] += val; // Assign value here.
        } else {
            int mid = (start + end)/2;
            if(pos <= mid) {
                update(node*2, start, mid, pos, val);
            } else {
                update(node*2 + 1, mid + 1, end, pos, val);
            }
            tree[node] = func(tree[node*2], tree[node*2 + 1]);
        }
    }

    T query(int node, int start, int end, int l, int r) {
        if(l > r) {
            return 0; // Return appropriate value, for example INF for minimum.
        }
        if(l == start && r == end) {
            return tree[node];
        }
        int mid = (start + end)/2;
        return func(query(node*2, start, mid, l, min(mid, r)), query(node*2 + 1, mid + 1, end, max(l, mid + 1), r));
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        SegTree <int> sa(4*n);
        SegTree <int> sb(4*n);
        int mn_a = n;
        int mn_b = n;
        int mx_a = 0;
        int mx_b = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] == '*') {
                sa.update(1, 0, n - 1, i, 1);
                mn_a = min(mn_a, i);
                mx_a = i;
            }
            if(b[i] == '*') {
                sb.update(1, 0, n - 1, i, 1);
                mn_b = min(mn_b, i);
                mx_b = i;
            }
        }
        if(sa.query(1, 0, n - 1, 0, n - 1) == 0) {
            cout << mx_b - mn_b << '\n';
            continue;
        }
        if(sb.query(1, 0, n - 1, 0, n - 1) == 0) {
            cout << mx_a - mn_a << '\n';
            continue;
        }
        if(mn_a <= mn_b && mx_a >= mx_b) {
            cout << mx_a - mn_a + sb.query(1, 0, n - 1, 0, n - 1) << '\n';
            continue;
        }
        if(mn_b <= mn_a && mx_b >= mx_a) {
            cout << mx_b - mn_b + sa.query(1, 0, n - 1, 0, n - 1) << '\n';
            continue;
        }
        if(mx_a <= mn_b) {
            cout << mx_b - mn_a + 1 << '\n';
            continue;
        }
        if(mx_b <= mn_a) {
            cout << mx_a - mn_b + 1 << '\n';
            continue;
        }
        if(mn_a <= mn_b) {
            int ans = abs(mn_b - mn_a) + abs(mx_b - mx_a);
            ans += mx_a - mn_b;
            int x = min(sa.query(1, 0, n - 1, mn_b + 1, mx_a - 1) + 1, sb.query(1, 0, n - 1, mn_b + 1, mx_a - 1) + 1);
            ans += x + 1;
            cout << ans << '\n';
        } else {
            int ans = abs(mn_b - mn_a) + abs(mx_b - mx_a);
            ans += mx_b - mn_a;
            int x = min(sa.query(1, 0, n - 1, mn_a + 1, mx_b - 1) + 1, sb.query(1, 0, n - 1, mn_a + 1, mx_b - 1) + 1);
            ans += x + 1;
            cout << ans << '\n';
        }
    }
    
    return 0;
}