#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    // dp[i][j] --> Number of ways of distributing j candies among first i children.
    int n, k;
    cin >> n >> k;
    int arr[n], dp[n][k+1];
    forn(i, 0, n) cin >> arr[i];
    forn(i, 0, n) forn(j, 0, k+1) dp[i][j] = 0;
    forn(i, 0, arr[0] + 1) dp[0][i] = 1;
    forn(i, 1, n) {
        int sum = 0;
        forn(j, 0, k+1) {
            if(j > arr[i]) {
                sum += dp[i-1][j] - dp[i-1][j - arr[i] - 1] + MOD; sum %= MOD; 
                dp[i][j] = sum;
            }
            else {
                sum += dp[i-1][j]; sum %= MOD;
                dp[i][j] = sum;
            }
        }
    }
    cout << dp[n-1][k];
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