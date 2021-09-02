#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    int n, k, p;
    cin >> n >> k >> p;
    int arr[n][k];
    forn(i, 0, n) forn(j, 0, k) cin >> arr[i][j];
    int grr[n][k];
    forn(i, 0, n) forn(j, 0, k) {
        if(j==0) grr[i][j] = arr[i][j];
        else grr[i][j] = grr[i][j-1] + arr[i][j];
    }
    int dp[n][p+1];
    memset(dp, 0, sizeof(dp));
    forn(i, 0, n) dp[i][0] = 0;
    forn(j, 1, p+1) {
        if(j <= k) dp[0][j] = grr[0][j - 1];
    }
    // Knapsack DP.
    forn(i, 1, n) forn(j, 1, p + 1) {
        dp[i][j] = dp[i-1][j];
        forn(x, 1, j + 1) {
            if(x > k || x > j) break;
            dp[i][j] = max(dp[i][j], dp[i-1][j-x] + grr[i][x-1]);
        }
    }
    int ans = 0;
    forn(i, 0, n) forn(j, 0, p + 1) ans = max(ans, dp[i][j]);
    cout << ans << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int T = 1;
    cin >> T;
    forn(I, 1, T+1) {
        cout << "Case #" << I << ": ";
        solve();
    }

    return 0;
}