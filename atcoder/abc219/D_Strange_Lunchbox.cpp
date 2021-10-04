#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 305;
const int MOD = 1000000007;

int dp[MAXN][MAXN*2][MAXN*2];

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    int A[n], B[n];
    forn(i, 0, n) cin >> A[i] >> B[i];
    memset(dp, n+1, sizeof(dp));
    forn(i, 0, n) dp[i][0][0] = 0;
    dp[0][A[0]][B[0]] = 1;
    forn(i, 1, n) forn(j, 0, MAXN) forn(k, 0, MAXN) {
        dp[i][j][k] = dp[i-1][j][k];
        if(j < A[i] || k < B[i]) continue;
        dp[i][j][k] = min(dp[i-1][j][k], dp[i-1][j-A[i]][k-B[i]] + 1);
    }
    int ans = n + 1;
    forn(a, 0, n) forn(i, x, MAXN) forn(j, y, MAXN) ans = min(ans, dp[a][i][j]);
    if(ans == n + 1) cout << -1;
    else cout << ans;
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