#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

/*
Note - Refer to Errichto's video for description of the method used.
TEST CASE - 
_<_>_<_<_ --> 9
1 3 2 4 5
1 4 2 3 5
1 5 2 3 4
2 3 1 4 5
2 4 1 3 5
2 5 1 3 4
3 4 1 2 5
3 5 1 2 4
4 5 1 2 3
*/

void solve() {
    int n;
    cin >> n;
    vector <char> v(n-1);
    forn(i, 0, n-1) cin >> v[i];
    int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    dp[1][1] = 1;
    forn(i, 2, n+1) {
        if(v[i-2]=='<') {
            dp[i][1] = 0;
            forn(j, 2, i + 1) {
                dp[i][j] = (dp[i][j-1] + dp[i-1][j-1]) % MOD;
            }
        }
        else {
            dp[i][i] = 0;
            for(int j = i - 1; j>=1; j--) {
                dp[i][j] = (dp[i][j+1] + dp[i-1][j]) % MOD;
            }
        }
    }
    // forn(i, 1, n+1) {forn(j, 1, n+1) cerr << dp[i][j] << " "; cerr << endl;}
    int ans = 0;
    forn(i, 1, n+1) ans = (ans + dp[n][i]) % MOD;
    cout << ans;
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