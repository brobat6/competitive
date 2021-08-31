#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    int n, w;
    cin >> n >> w;
    int wt[n], val[n], dp[n][w+1];
    forn(i, 0, n) cin >> wt[i] >> val[i];
    forn(i, 0, w+1) dp[0][i] = 0;
    dp[0][wt[0]] = val[0];
    forn(i, 1, n) dp[i][0] = 0;
    forn(i, 1, n) {
        forn(j, 1, w+1) {
            if(j < wt[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-wt[i]] + val[i]);
        }
    }
    int max_val = 0;
    forn(i, 0, w+1) max_val = max(max_val, dp[n-1][i]);
    cout << max_val;
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