#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
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

void solve() {
    pre();
    int h, w, n;
    cin >> h >> w >> n;
    vector <pair<int, int>> v(n+1);
    int dp[n+1];
    forn(i, 0, n) cin >> v[i].first >> v[i].second;
    v[n] = {h, w};
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
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}