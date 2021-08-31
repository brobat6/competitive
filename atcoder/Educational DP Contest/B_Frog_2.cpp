#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    int n, k;
    cin >> n >> k;
    int arr[n], dp[n];
    forn(i, 0, n) cin >> arr[i];
    dp[0] = 0;
    forn(i, 1, n) {
        dp[i] = MOD;
        forn(j, 1, k+1) {
            int x = max(0ll, i - j);
            dp[i] = min(dp[i], dp[x] + abs(arr[x] - arr[i]));
        }
    }
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