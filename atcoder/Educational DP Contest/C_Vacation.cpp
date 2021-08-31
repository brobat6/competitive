#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    int n;
    cin >> n;
    int arr[n][3], dp[n][3];
    forn(i, 0, n) forn(j, 0, 3) cin >> arr[i][j];
    forn(i, 0, 3) dp[0][i] = arr[0][i];
    forn(i, 1, n) {
        dp[i][0] = arr[i][0] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = arr[i][1] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = arr[i][2] + max(dp[i-1][0], dp[i-1][1]);
    }
    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
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