#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[22][(1<<20) + 5];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    clock_t start = clock();

    vector <int> slot(2*k);
    for(int i = 0; i < 2*k; i++) {
        slot[i] = (i + 2)/2;
    }

    int m = 2*k;

    memset(dp, 0, sizeof(dp));
    for(int c = 1; c <= n; c++) {
        for(int i = 0; i < (1<<m); i++) {
            for(int j = 0; j < m; j++) {
                if((i >> j) & 1) {
                    dp[c][i] = max(dp[c][i], dp[c - 1][i - (1<<j)] + (slot[j] & v[c - 1]));
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < (1<<m); j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';

    clock_t end = clock();
    
    cout << (double)(end - start)/CLOCKS_PER_SEC << '\n';

    return 0;
}