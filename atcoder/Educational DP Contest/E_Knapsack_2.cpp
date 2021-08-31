#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    // int dp[N][V] = W.
    int n, w;
    cin >> n >> w;
    int V = 1000*n + 10;
    int wt[n], val[n], dp[n][V];
    forn(i, 0, n) cin >> wt[i] >> val[i];
    forn(i, 0, n) forn(j, 0, V) dp[i][j] = MOD;
    dp[0][val[0]] = wt[0];
    forn(i, 1, n) {
        forn(j, 0, V) {
            dp[i][j] = dp[i-1][j];
            if(j < val[i]) continue;
            if(j == val[i]) dp[i][j] = min(dp[i][j], wt[i]);
            else if(dp[i-1][j - val[i]] != MOD) dp[i][j] = min(dp[i][j], dp[i-1][j-val[i]] + wt[i]);
        }
    }
    for(int j = V - 1; j>=0; j--) {
        forn(i, 0, n) {
            if(dp[i][j] <= w) {
                cout << j;
                return;
            }
        }
    }
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