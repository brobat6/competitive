#include <bits/stdc++.h>
using namespace std;
 
int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

void solve() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m));
        vector<vector<int>> score(n, vector<int>(m, -1));
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        queue <pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'R') {
                    q.push({i, j});
                    score[i][j] = 0;
                }
            }
        }
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int k = 0; k < 4; k++) {
                int i = x + dir[k][0];
                int j = y + dir[k][1];
                if(i < 0 || i >= n || j < 0 || j >= m) {
                    continue;
                }
                if(score[i][j] == -1) {
                    score[i][j] = score[x][y] + 1;
                    q.push({i, j});
                }
            }
        }
            dp[n - 1][m - 1] = score[n - 1][m - 1];
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                if(i == n - 1 && j == m - 1) {
                    continue;
                }
                if(i == n - 1) {
                    dp[i][j] = dp[i][j + 1] + score[i][j];
                }
                else if(j == m - 1) {
                    dp[i][j] = dp[i + 1][j] + score[i][j];
                }
                else {
                    if((i + j) % 2 == 0) {
                        // Alice's turn
                        dp[i][j] = score[i][j] + max(dp[i + 1][j], dp[i][j + 1]);
                    } else {
                        // Bob's turn
                        dp[i][j] = score[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
                    }
                }
            }
        }
        cout << dp[0][0] << endl;
    }
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
   
    for(int i = 0; i <= 15; i++) {
        string a = to_string(i) + ".in";
        string b = to_string(i) + ".out";
        freopen(a.c_str(), "r", stdin);
        freopen(b.c_str(), "w", stdout);
        solve();
    }
   
    return 0;
}