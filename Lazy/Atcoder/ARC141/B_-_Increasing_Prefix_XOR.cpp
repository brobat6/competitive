#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 998244353;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    int x = 0, y = 1;
    while(y <= m) {
        x++;
        y <<= 1ll;
    }
    if(n > x) {
        cout << 0;
        return 0;
    }
    vector<int> v(x + 1, 0);
    for(int i = 1; i <= x; i++) {
        int a = 1ll<<(i - 1);
        int b = a<<1ll;
        v[i] = min(b - a, m - a + 1) % MOD;
        // cout << v[i] << " ";
    }
    int dp[x + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= x; i++) {
        dp[i][1] = v[i];
    }
    for(int i = 2; i <= n; i++) {
        // i values are done.
        for(int j = 1; j <= x; j++) {
            // currently dealing with j^th bit.
            for(int k = 1; k < j; k++) {
                // previous value done was k^th.
                dp[j][i] = (dp[j][i] + (dp[k][i - 1] * v[j] % MOD)) % MOD;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= x; i++) {
        ans = (ans + dp[i][n]) % MOD;
    }
    cout << ans << '\n';

    // for(int i = 1; i <= x; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    
    return 0;
}