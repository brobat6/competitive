#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 1000100;
const int MOD = 1000000007;

// dp[i] --> The number of ways assuming the ith vertex is the first one reached in v
// (All previous vertices in the vector v have not been reached).

int fact[MAXN];
int inv_fact[MAXN];

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res % MOD;
}

int nCr(int a, int b) {
    if(a < 0 || b < 0 || b > a) return 0;
    return fact[a] * inv_fact[b] % MOD * inv_fact[a - b] % MOD;
}

int find(int a, int b) {
    return nCr(a + b, b);
}

void pre() {
    fact[0] = inv_fact[0] = 1;
    forn(i, 1, MAXN) {
        fact[i] = (fact[i-1]*i) % MOD;
        inv_fact[i] = binpow(fact[i], MOD - 2);
    }
}

void solve(vector<pair<int, int>> &v, int n, int h, int w) {
    pre();
    int dp[n + 1];
    sort(v.begin(), v.end());
    forn(i, 0, n+1) {
        dp[i] = find(v[i].first - 1, v[i].second - 1);
        forn(j, 0, i) {
            if(v[j].second > v[i].second) continue;
            int x = dp[j] * find(v[i].first - v[j].first, v[i].second - v[j].second) % MOD;
            dp[i] = (dp[i] - x + MOD) % MOD;
        }
    }
    cout << dp[n] << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int n, m, h, w;
    cin >> n >> m >> h >> w;
    set<int> s;
    for(int i = 0; i < n; i++) {
        int x; cin >> x; s.insert(x);
    }
    vector<pair<int, int>> v;
    for(auto i : s) {
        int x = i / m;
        int y = i % m;
        if(x > h || y > w) continue;
        if(x == h && y == w) {
            cout << 0;
            return 0;
        }
        v.push_back({x, y});
    }
    v.push_back({h, w});
    n = (int)v.size() - 1;
    for(int i = 0; i <= n; i++) {
        v[i].first++;
        v[i].second++;
    }
    solve(v, n, h, w);

    // solve();

    return 0;
}
