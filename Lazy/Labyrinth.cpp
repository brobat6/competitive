#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    char dir_name[4] = {'D', 'R', 'U', 'L'};
    
    int n, m;
    cin >> n >> m;
    char grid[n][m];
    pair<int, int> start;
    pair<int, int> end;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'A') {
                start = {i, j};
            }
            if(grid[i][j] == 'B') {
                end = {i, j};
            }
        }
    }
    int dist[n][m];
    char pre_name[n][m];
    pair<int, int> pre[n][m];
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> q;
    q.push(start);
    dist[start.first][start.second] = 0;
    while(!q.empty()) {
        auto [a, b] = q.front();
        q.pop();
        for(int k = 0; k < 4; k++) {
            int x = a + dir[k][0];
            int y = b + dir[k][1];
            if(x < 0 || y < 0 || x >= n || y >= m) continue;
            if(grid[x][y] == '#') continue;
            if(dist[x][y] == -1) {
                dist[x][y] = dist[a][b] + 1;
                pre_name[x][y] = dir_name[k];
                pre[x][y] = {a, b};
                q.push({x, y});
            }
        }
    }
    if(dist[end.first][end.second] == -1) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << '\n';
    cout << dist[end.first][end.second] << '\n';
    pair<int, int> temp = end;
    vector<char> ans;
    while(temp != start) {
        ans.push_back(pre_name[temp.first][temp.second]);
        temp = pre[temp.first][temp.second];
    }
    reverse(ans.begin(), ans.end());
    for(auto i : ans) cout << i;

    return 0;
}