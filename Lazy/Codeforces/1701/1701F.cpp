#include <bits/stdc++.h>
using namespace std;
#define int long long

class SegTree {
public:

    vector <int> sum, square, cnt, lazy;
 
    SegTree(int size) {
        sum.resize(size, 0);
        square.resize(size, 0);
        cnt.resize(size, 0);
        lazy.resize(size, 0);
    }
 
    void push(int n) {
        square[n * 2] += lazy[n]*lazy[n]*cnt[n*2] + 2*sum[n*2]*lazy[n];
        sum[n * 2] += lazy[n]*cnt[n*2];
        lazy[n * 2] += lazy[n];
        square[n*2 + 1] += lazy[n]*lazy[n]*cnt[n*2+1] + 2*sum[n*2+1]*lazy[n];
        sum[n*2 + 1] += lazy[n]*cnt[n*2+1];
        lazy[n*2 + 1] += lazy[n];
        lazy[n] = 0;
    }

    void update_count(int node, int start, int end, int pos, int val) {
        if(start == end) {
            cnt[node] += val;
        } else {
            int mid = (start + end)/2;
            if(pos <= mid) {
                update_count(node*2, start, mid, pos, val);
            } else {
                update_count(node*2 + 1, mid + 1, end, pos, val);
            }
            cnt[node] = cnt[node * 2] + cnt[node * 2 + 1];
        }
    }

    int query_count(int node, int start, int end, int l, int r) {
        if(l > r) return 0;
        if(l == start && r == end) {
            return cnt[node];
        }
        int mid = (start + end)/2;
        return query_count(node*2, start, mid, l, min(mid, r)) + query_count(node*2 + 1, mid + 1, end, max(l, mid + 1), r);
    }
 
    void update_range(int node, int start, int end, int l, int r, int val) {
        // Add val to [l, r].
        if(cnt[node] == 0) return;
        if(start == end) {
            // cerr << l << " " << r << " " << val << '\n';
            square[node] += val*val*cnt[node] + 2*sum[node]*val;
            sum[node] += val*cnt[node];
            lazy[node] = 0;
            return;
        }
        if(l == start && r == end) {
            square[node] += val*val*cnt[node] + 2*val*sum[node];
            sum[node] += val*cnt[node];
            lazy[node] += val;
            lazy[node] += val;
        } else {
            push(node);
            int mid = (start + end)/2;
            if(l <= mid) update_range(node * 2, start, mid, l, min(r, mid), val);
            if(r > mid) update_range(node * 2 + 1, mid + 1, end, max(l, mid + 1), r, val);
            // tree[node] = tree[node * 2] + tree[node * 2 + 1];
            sum[node] = sum[node * 2] + sum[node * 2 + 1];
            square[node] = square[node * 2] + square[node * 2 + 1];
        }
    }

    void reset_value(int node, int start, int end, int l, int r) {
        if(start == end) {
            square[node] = 0;
            sum[node] = 0;
            lazy[node] = 0;
            return;
        } else {
            push(node);
            int mid = (start + end)/2;
            if(l <= mid) reset_value(node * 2, start, mid, l, min(r, mid));
            if(r > mid) reset_value(node * 2 + 1, mid + 1, end, max(l, mid + 1), r);
            // tree[node] = tree[node * 2] + tree[node * 2 + 1];
            sum[node] = sum[node * 2] + sum[node * 2 + 1];
            square[node] = square[node * 2] + square[node * 2 + 1];
        }
    }
 
    pair<int, int> query(int node, int start, int end, int l, int r) {
        if(start == end) {
            return {sum[node], square[node]};
        }
        if(l == start && r == end) {
            return {sum[node], square[node]};
        }
        push(node);
        int mid = (start + end)/2;
        pair<int, int> a = {0, 0}, b = {0, 0};
        if(l <= mid) a = query(node * 2, start, mid, l, min(r, mid));
        if(r > mid) b = query(node * 2 + 1, mid + 1, end, max(l, mid + 1), r);
        return {a.first + b.first, a.second + b.second};
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int q, d;
    cin >> q >> d;
    int n = 200100;
    SegTree st(4*n);
    vector <int> v(n, 0);
    for(int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if(v[x] == 1) {
            st.update_range(1, 0, n - 1, max(x - d, 0ll), x - 1, -1);
            int ahead = st.query_count(1, 0, n - 1, min(x + 1, n), min(x + d, n));
            st.reset_value(1, 0, n - 1, x, x);
            st.update_count(1, 0, n - 1, x, -1);
            v[x] = 0;
        } else {
            st.update_range(1, 0, n - 1, max(x - d, 0ll), x - 1, 1);
            int ahead = st.query_count(1, 0, n - 1, min(x + 1, n), min(x + d, n));
            // cerr << ahead << '\n';
            st.update_count(1, 0, n - 1, x, 1);
            st.update_range(1, 0, n - 1, x, x, ahead);
            v[x] = 1;
        }
        auto ans = st.query(1, 0, n - 1, 0, n - 1);
        cout << (ans.second - ans.first)/2 << '\n';

        cerr << "After query " << i + 1 << '\n';

        for(int i = 0; i < 10; i++) {
            auto x = st.query(1, 0, n - 1, i, i);
            cerr << x.first << " " << x.second << '\n';
        }

    }
    
    return 0;
}