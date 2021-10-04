#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 300100;
const int MOD = 998244353;

int pw[MAXN], inv[MAXN];

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res % MOD;
}

void pre() {
    pw[0] = 1; inv[0] = binpow(1, MOD - 2);
    forn(i, 1, MAXN) {
        pw[i] = (pw[i-1] * 2) % MOD;
        inv[i] = binpow(pw[i], MOD - 2);
    }
}

bool comp(pair<int, int>a, pair<int, int>b) {
    if(a.first==b.first) return a.second > b.second;
    return a.first > b.first;
}

int func(int a, int b) {
    return (a + b) % MOD;
}

int query(vector<int> &st, int v, int tl, int tr, int l, int r) {
    if(l > r) return 0; // Return appropriate value, for example INF for find_min.
    if(l==tl && r==tr) return st[v];
    int tm = (tl + tr)/2;
    return func(query(st, v*2, tl, tm, l, min(r, tm)), query(st, v*2 + 1, tm + 1, tr, max(l, tm+1), r));
}

void update(vector<int> &st, int v, int tl, int tr, int pos, int new_val) {
    if(tl==tr) st[v] = new_val; // Assign value here.
    else {
        int tm = (tl + tr)/2;
        if(pos <= tm) update(st, v*2, tl, tm, pos, new_val);
        else update(st, v*2 + 1, tm+1, tr, pos, new_val);
        st[v] = func(st[v*2], st[v*2 + 1]);
    }
}

void solve() {
    pre();
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    forn(i, 0, n) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end(), comp);
    vector<int> st(4*n, 0);
    int ans = 0;
    forn(i, 0, n) {
        update(st, 1, 0, n-1, v[i].second, pw[v[i].second]);
        int x = query(st, 1, 0, n-1, v[i].second + 1, n - 1);
        // cout << x << " " << x * inv[v[i].second + 1] % MOD << endl;
        ans += (x * inv[v[i].second + 1] % MOD);
        ans %= MOD;
    }
    cout << ans;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}