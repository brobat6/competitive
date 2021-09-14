#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 20000100;
const int MOD = 998244353;

int P[MAXN], A[MAXN];
int n, m;
int Q[MAXN], L[MAXN];

void pre() {
    P[0] = 0; P[1] = 1;
    forn(i, 2, MAXN) P[i] = (P[i-1] * 31) % MOD;
    L[0] = 0; Q[0] = 0;
    forn(i, 1, MAXN) {
        L[i] = (L[i-1] + i) % MOD;
        Q[i] = (Q[i-1] + i*i) % MOD;
    }
}

void solve() {
    cin >> n >> m;
    if(n > m) swap(n, m);
    forn(i, 0, n - m + 1) A[i] = 0;
    forn(x, 0, n + m - 1) {
        int lower = max(0ll, x - m);
        int upper = min(x, n);
        // Find sum of (n - i)(m - (x - i)) where i varies from lower to upper.
        // (nm-nx) + i(n-m+x) - i*i from upper to lower.
        int a1 = n*(m + MOD - x) % MOD * (upper - lower + 1);
        int a2 = (n - m + x + MOD) % MOD * (L[upper] - L[max(0ll, lower - 1)] + MOD) % MOD;
        int a3 = (Q[upper] - Q[max(0ll, lower - 1)] + MOD) % MOD;
        A[x] = 2 * (a1 + a2 - a3 + MOD) % MOD;
        if(x < m) A[x] = (A[x] + MOD - (n*(m-x)%MOD)) % MOD;
        if(x < n) A[x] = (A[x] + MOD - (m*(n-x)%MOD)) % MOD;
    }
    int ans = 0;
    forn(i, 0, n + m - 1) {
        ans = (ans + A[i]*P[i]) % MOD;
    }
    cout << ans << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    pre();
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}