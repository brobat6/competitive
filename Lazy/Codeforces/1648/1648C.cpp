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

    T func(T a, T b) {
        return a + b; // Segment tree for the sum
        // return min(a, b); // Segment tree for the minimum
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

const int MOD = 998244353;
const int MAXN = 200100;

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res % MOD;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    int fact[n + 1];
    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    vector <int> b(m);
    map <int, int> cnt;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        cnt[temp]++;
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int ind = 0; // The first index at which strings HAVE to differ
    for(int i = 0; i < min(n, m); i++) {
        if(cnt[b[i]] > 0) {
            cnt[b[i]]--;
            ind++;
        } else {
            break;
        }
    }
    int num = 1;
    int den = 1;
    int length = n - ind;
    SegTree <int> st(4*MAXN);
    for(auto i : cnt) {
        for(int j = 0; j < i.second; j++) {
            st.update(1, 0, n - 1, i.first, 1);
            den = (den * (j + 1)) % MOD;
        }
    }
    num = fact[n - ind];
    // cout << num << " " << den << endl;
    int ans = 0;
    // ans = (ans + num * binpow(den, MOD - 2)) % MOD;
    for(int i = ind; i >= 0; i--) {
        if(i == ind && i >= m) {
            continue;
        }
        ans = (ans + (num * binpow(den, MOD - 2) % MOD) * length % MOD * binpow(st.query(1, 0, MAXN - 1, 1, b[i] - 1), MOD - 2)) % MOD;
        length++;
        st.update(1, 0, MAXN - 1, b[i], 1);
        num = (num * length) % MOD;
        int x = st.query(1, 0, MAXN - 1, b[i], b[i]);
        den = (den * x) % MOD;
    }
    cout << ans << endl;
    
    return 0;
}