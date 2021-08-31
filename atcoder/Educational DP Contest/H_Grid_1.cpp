#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    int h, w;
    cin >> h >> w;
    char arr[h][w];
    int dp[h+1][w+1];
    forn(i, 0, h) forn(j, 0, w) cin >> arr[i][j];
    forn(i, 0, h+1) forn(j, 0, w+1) dp[i][j] = 0;
    dp[1][1] = 1;
    forn(i, 1, h+1) {
        forn(j, 1, w+1) {
            if(arr[i-1][j-1]=='.') {
                dp[i][j] += dp[i-1][j] + dp[i][j-1];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[h][w];
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