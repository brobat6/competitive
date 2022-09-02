#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector <int> dp(n, n + 5);
        dp[0] = 0;
        vector <int> mx(n + 1, n + 5);
        mx[v[0]] = 0;
        int curr = 0;
        for(int i = 1; i < n; i++) {
            if(v[i] >= v[i - 1]) {
                dp[i] = min(dp[i], curr);
                dp[i] = min(dp[i], mx[v[i]] + 1);
                curr = min(curr, dp[i]);
            } else {
                dp[i] = min(dp[i], mx[v[i]] + 1);
                curr = dp[i];
            }
            mx[v[i]] = min(mx[v[i]], dp[i]);
        }
        // cout << max(dp[n - 1], -1) << '\n';
        if(dp[n - 1] >= n) cout << -1 << '\n';
        else cout << dp[n - 1] << '\n';
    }
    
    return 0;
}