#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    int n;
    cin >> n;
    double dp[n][n+1], arr[n];
    forn(i, 0, n) cin >> arr[i];
    forn(i, 0, n) forn(j, 0, n+1) dp[i][j] = 0.0;
    dp[0][1] = arr[0];
    dp[0][0] = 1 - arr[0];
    forn(i, 1, n) {
        forn(j, 0, i+1) {
            dp[i][j] += dp[i-1][j]*(1 - arr[i]);
            dp[i][j+1] += dp[i-1][j]*arr[i];
        }
    }
    double ans = 0.0;
    forn(j, n/2 + 1, n+1) ans += dp[n-1][j];
    cout << setprecision(15) << ans;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}