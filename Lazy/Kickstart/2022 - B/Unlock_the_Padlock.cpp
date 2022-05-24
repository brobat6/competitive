#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, d;
    cin >> n >> d;
    vector <int> v(n + 2, 0);
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int dp[n + 2][n + 2][2];
    memset(dp, 0, sizeof(dp));
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i + k - 1 <= n; i++) {
            int j = i + k - 1;
            if(i == j) {
                dp[i][j][0] = min(abs(v[i] - v[i - 1]), d - abs(v[i] - v[i - 1]));
                dp[i][j][1] = min(abs(v[i] - v[i + 1]), d - abs(v[i] - v[i + 1]));
            } else {
                dp[i][j][0] = min(dp[i + 1][j][0] + min(abs(v[i] - v[i - 1]), d - abs(v[i] - v[i - 1])), dp[i][j - 1][1] + min(abs(v[j] - v[i - 1]), d - abs(v[j] - v[i - 1])));
                dp[i][j][1] = min(dp[i + 1][j][0] + min(abs(v[i] - v[j + 1]), d - abs(v[i] - v[j + 1])), dp[i][j - 1][1] + min(abs(v[j] - v[j + 1]), d - abs(v[j] - v[j + 1])));
            }
        }
    }
    cout << min(dp[1][n][0], dp[1][n][1]) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    for(int I = 1; I <= t; I++) {
        cout << "Case #" << I << ": ";
        solve();
    }
    
    return 0;
}