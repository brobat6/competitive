#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    int grid[n][n];
    memset(grid, -1, sizeof(grid));
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int curr = 0;
    int ci = 0;
    int cj = 0;
    for(int i = 1; i <= n*n; i++) {
        grid[ci][cj] = i;
        int x = ci + dir[curr][0];
        int y = cj + dir[curr][1];
        if(x < 0 || y < 0 || x >= n || y >= n || grid[x][y] != -1) {
            curr = (curr + 1) % 4;
        }
        ci += dir[curr][0];
        cj += dir[curr][1];
    }
    map<int, pair<int, int>> pos;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            pos[grid[i][j]] = {i, j};
        }
    }
    int dp[n*n + 5][n*n + 5];
    memset(dp, -1, sizeof(dp));
    dp[n*n][0] = 0;
    for(int a = n*n - 1; a >= 1; a--) {
        int i = pos[a].first;
        int j = pos[a].second;
        for(int b = 0; b < 4; b++) {
            int x = i + dir[b][0];
            int y = j + dir[b][1];
            if(x < 0 || y < 0 || x >= n || y >= n) continue;
            for(int c = 0; c <= n*n; c++) {
                if(dp[grid[x][y]][c] == -1) continue;
                int nx = grid[x][y];
                // update dp[a][c + 1] based on dp[nx][c].
                if(nx > a) {
                    if(dp[a][c + 1] == -1) {
                        dp[a][c + 1] = nx;
                    }
                }
            }
        }
    }
    if(dp[1][k] == -1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    vector<int> ans;
    curr = 1;
    int mov = k;
    ans.push_back(curr);
    while(curr != n*n) {
        curr = dp[curr][mov];
        mov--;
        ans.push_back(curr);
    }
    int z = ans.size();
    vector <pair<int, int>> anss;
    for(int i = 1; i < z; i++) {
        if(ans[i] != ans[i - 1] + 1) {
            anss.push_back({ans[i], ans[i - 1]});
        }
    }
    cout << (int)anss.size() << '\n';
    reverse(ans.begin(), ans.end());
    for(auto i : anss) {
        cout << i.second << " " << i.first << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    
    return 0;
}