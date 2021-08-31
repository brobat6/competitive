#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    int n;
    cin >> n;
    int arr[n], dp[n][n], sum[n+1];
    forn(i, 0, n) cin >> arr[i];
    sum[0] = 0;
    forn(i, 0, n) sum[i+1] = sum[i] + arr[i];
    // dp[i][j] --> The optimal answer for i...j // Brute force and check for all subsequences.
    forn(i, 0, n) dp[i][i] = arr[i];
    forn(i, 0, n-1) dp[i][i+1] = arr[i] + arr[i+1];
    forn(k, 2, n) {
        forn(i, 0, n - k) {
            int j = i + k;
            dp[i][j] = min(arr[i] + dp[i+1][j] + sum[j+1] - sum[i+1], sum[j] - sum[i] + dp[i][j-1] + arr[j]);
            for(int x = i + 1; x < j - 1; x++) {
                dp[i][j] = min(dp[i][j], dp[i][x] + dp[x+1][j] + sum[j+1] - sum[i]);
            }
        }
    }
    cout << dp[0][n-1];
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