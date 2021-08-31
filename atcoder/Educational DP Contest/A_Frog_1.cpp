#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    int n;
    cin >> n;
    int arr[n], dp[n];
    forn(i, 0, n) cin >> arr[i];
    dp[0] = 0;
    dp[1] = abs(arr[1] - arr[0]);
    forn(i, 2, n) dp[i] = min(dp[i-1] + abs(arr[i-1] - arr[i]), dp[i-2] + abs(arr[i-2] - arr[i]));
    cout << dp[n-1];
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