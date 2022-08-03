#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k, MOD;
    cin >> n >> k >> m >> MOD;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector <int> p(n + k), c(n + k);
    for(int i = 0; i < n + k; i++) {
        cin >> p[i];
    }
    for(int i = 0; i < n + k; i++) {
        cin >> c[i];
    }
    vector<vector<pair<int, int>>> dp(n + k + 2, vector<pair<int, int>>(k + 1, {-(int)1, 0})); // CHANGE TO 1e18
    dp[1][0] = {0, 1};
    // cout << "F";
    for(int i = 1; i <= n + k + 1; i++) {
        for(int j = max(i - n - 1, 0ll); j <= min(k, i - 1); j++) {
            cout << i << " " << j << " reached\n";
            // dp[i][j] is known.
            if(i != 1 && j != 0 && (i - j - 2) >= 0 && (i - j - 2) < n) {
                // subtract some values from dp[i][j], if both (i - 1, j) and (i - 1, j - 1) contributed to the answer
                // and both were same!!!
                int pos1 = dp[i - 1][j - 1].first + c[i - 2];
                if(m != 1) pos1 = max(pos1, dp[i - 1][j - 1].first);
                int pos2 = (v[i - j - 2] == p[i - 2] ? dp[i - 1][j].first + c[i - 2] : dp[i - 1][j].first);

            }
            

            if(i == n + k + 1) {
                
                continue;
            }
            if(j < k && i <= n + k) {
                // update dp[i + 1][j + 1].
                // new value based on whether c[i - 1] is positive or negative. 
                // special case for m = 1
                int pos = dp[i][j].first + c[i - 1];
                // if(i == 2 && j == 0) cout << pos << '\n';
                if(m != 1) {
                    pos = max(pos, dp[i][j].first);
                } 
                if(pos > dp[i + 1][j + 1].first) {
                    dp[i + 1][j + 1] = {pos, dp[i][j].second};
                } else if(pos == dp[i + 1][j + 1].first) {
                    dp[i + 1][j + 1].second += dp[i][j].second;
                    dp[i + 1][j + 1].second %= MOD;
                }
            }
            if(i - j - 1 >= 0 && i - j - 1 < n && i <= n + k) {
                // insert v[i - j - 1] at position i.
                // if(i == 3 && j == 1) cout << "f";
                int pos;
                if(v[i - j - 1] == p[i - 1]) {
                    pos = dp[i][j].first + c[i - 1];
                    if(i == 3 && j == 1) cout << dp[i][j].first << " " << c[i - 1] << " " << pos << '\n';
                } else {
                    pos = dp[i][j].first;
                }
                if(pos > dp[i + 1][j].first) {
                    dp[i + 1][j] = {pos, dp[i][j].second};
                } else if(pos == dp[i + 1][j].first) {
                    dp[i + 1][j].second += dp[i][j].second;
                    dp[i + 1][j].second %= MOD;
                }   
            }
        }
    }
    for(int i = 0; i <= n + k + 1; i++) {
        for(int j = 0; j <= k; j++) {
            cerr << "{" << dp[i][j].first << "," << dp[i][j].second << "},";
        }
        cerr << "\n\n";
    }
    cout << dp[n + k + 1][k].first << " " << dp[n + k + 1][k].second << '\n';
    
    return 0;
}