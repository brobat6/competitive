#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    // (a, b) ----> (a + 1, b) (a, b+1) (a -1, b) (a, b - 1)
    // run a for loop for(int i = 0; i < 4; i++) 
    // i --> (x, y) = (a + dir[i][0], b + dir[i][1])
    
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
    // dist[i][j] --> min. distance from source to the vertex (i, j).
    memset(dist, -1, sizeof(dist));

    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         dist[i][j] = -1;
    //     }
    // }

    queue<pair<int, int>> q;
    q.push(start);
    dist[start.first][start.second] = 0;

    while(!q.empty()) {
        auto [a, b] = q.front();

        // int a = q.front().first;
        // int b = q.front().second;

        q.pop();

        for(int k = 0; k < 4; k++) {
            // (x, y)
            int x = a + dir[k][0];
            int y = b + dir[k][1];

            // 0 <= x < n AND 0 <= y < m
            if(x < 0 || y < 0 || x >= n || y >= m) continue;
            
            if(grid[x][y] == '#') continue;
            
            if(dist[x][y] == -1) {
                dist[x][y] = dist[a][b] + 1;
                q.push({x, y});
            }
        }
    }

    if(dist[end.first][end.second] == -1) {
        cout << "NO";
    } else {
        cout << "YES";
    }

    return 0;
}