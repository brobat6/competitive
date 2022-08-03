#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
class SegTree {
public:
    vector <T> tree;

    SegTree(int size) {
        tree.resize(size);
        for(int i = 0; i < size; i++) {
            tree[i] = 0;
        }
    }

    T func(T a, T b) {
        return a + b; // Segment tree for the sum
        // return min(a, b); // Segment tree for the minimum
    }

    void update(int node, int start, int end, int pos, T val) {
        if(start == end) {
            tree[node] = val; // Assign value here.
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
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i].first;
            v[i].second = i;
        }
        sort(v.begin(), v.end());
        vector<vector<int>> r;
        int left = v[0].second;
        int right = v[0].second;
        r.push_back({v[0].second, v[0].second, v[0].second});
        for(int i = 1; i < n; i++) {
            int x = v[i].second;
            if(x < left || x > right) {
                r.push_back({x, x, x});
            } else {
                r.push_back({left, x, right});
            }
            left = min(left, x);
            right = max(right, x);
        }
        // for(int i = 0; i < n; i++) {
        //     cout << r[i][0] << " " << r[i][1] << " " << r[i][2] << '\n';
        // }
        int ans = 0;
        SegTree<int> st(4*n);
        for(int i = n - 1; i >= 0; i--) {
            int x = r[i][1];
            int lt = r[i][0];
            int rt = r[i][2];
            ans += st.query(1, 0, n - 1, lt, rt);
            st.update(1, 0, n - 1, x, 1);
        }
        cout << ans << '\n';
        // int cnt = 0;
        // SegTree<int> st(4*n);
        // for(int i = 0; i < n; i++) {
        //     int pos = v[i].second;
        //     int cnt1 = st.query(1, 0, n - 1, 0, pos - 1);
        //     int cnt2 = st.query(1, 0, n - 1, pos + 1, n - 1);
        //     if(cnt1 != 0 && cnt2 != 0) cnt++; 
        //     st.update(1, 0, n - 1, pos, 1);
        // }
        // cout << cnt*(cnt - 1)/2 << '\n';
    }
    
    return 0;
}