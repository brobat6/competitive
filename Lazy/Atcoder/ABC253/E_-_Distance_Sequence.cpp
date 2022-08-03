#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 998244353;

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res % MOD;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    if(k == 0) {
        cout << binpow(m, n);
        return 0;
    }
    int dp[n][m];
    int pd[n][m];
    memset(dp, 0, sizeof(dp));
    pd[0][0] = 1;
    for(int i = 0; i < m; i++) {
        dp[0][i] = 1;
        if(i != 0) pd[0][i] = pd[0][i - 1] + 1;
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {
            // calculate dp[i][j].
            if(j >= k) dp[i][j] = (dp[i][j] + pd[i - 1][j - k]) % MOD;
            if(j + k - 1 < m) {
                dp[i][j] = (dp[i][j] + pd[i - 1][m - 1] + MOD - pd[i - 1][j + k - 1]) % MOD;
            }
        }
        pd[i][0] = dp[i][0];
        for(int j = 1; j < m; j++) {
            pd[i][j] = (pd[i][j - 1] + dp[i][j]) % MOD;
        }
    }
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    cout << pd[n - 1][m - 1] << '\n';
    
    return 0;
}