#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    int n;
    cin >> n;
    int arr[n], dp[n][n][2];
    forn(i, 0, n) cin >> arr[i];
    forn(i, 0, n) {
        dp[i][i][0] = arr[i];
        dp[i][i][1] = -arr[i];
    }
    forn(k, 1, n) { // The difference
        forn(i, 0, n - k) { // The starting value
            int j = i + k;
            dp[i][j][0] = max(dp[i][j-1][1] + arr[j], dp[i+1][j][1] + arr[i]);
            dp[i][j][1] = min(dp[i][j-1][0] - arr[j], dp[i+1][j][0] - arr[i]); 
        }
    }
    cout << dp[0][n-1][0];
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