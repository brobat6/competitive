#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    map <int, int> bonus;
    for(int i = 0; i < n; i++) {
        pair<int, int> temp;
        cin >> temp.first >> temp.second;
        bonus.insert(temp);
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        dp[i][0] = *max_element(dp[i - 1].begin(), dp[i - 1].end());
        for(int j = 1; j <= n; j++) {
            if(dp[i - 1][j - 1] == -1) continue;
            dp[i][j] = dp[i - 1][j - 1] + v[i - 1];
            if(bonus.find(j) != bonus.end()) {
                dp[i][j] += bonus[j];
            }
        }
    }
    cout << (*max_element(dp[n].begin(), dp[n].end()));
    
    return 0;
}