#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 998244353;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            for(int x = j + k + i; x <= n; x += k + i) {
                dp[i + 1][x] += dp[i][j];
                dp[i + 1][x] %= MOD;
            }
        }
    }
    int ans[n + 1];
    memset(ans, 0, sizeof(ans));
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            ans[j] += dp[i][j];
            ans[j] %= MOD;
        }
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
    
    return 0;
}