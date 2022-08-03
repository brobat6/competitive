#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 104;
const int MOD = 998244353;

int dp[N][N][N][N];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    memset(dp, 0, sizeof(dp));
    // for(int k = 1; k <= n; k++) {
    //     dp[0][0][k][arr[0] % k]++;
    // }
    for(int i = 0; i < n; i++) {
        for(int k = 1; k <= n; k++) {
            dp[i][0][k][arr[i] % k]++;
        }
    }
    for(int i = 1; i < n; i++) {
        for(int k = 1; k <= n; k++) {
            for(int l = 0; l < k; l++) {
                for(int j = 0; j <= i; j++) {
                    dp[i][j][k][l] += dp[i - 1][j][k][l];
                    if(j > 0) {
                        dp[i][j][k][l] += dp[i - 1][j - 1][k][(l - (arr[i] % k) + k) % k];
                    }
                    dp[i][j][k][l] %= MOD;
                }
            }
        }
    }
    int ans = 0;
    for(int k = 1; k <= n; k++) {
        ans = (ans + dp[n - 1][k - 1][k][0]) % MOD;
    }
    cout << ans;
    
    return 0;
}