#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    --a; --b;
    int c, d;
    cin >> c >> d;
    --c; --d;
    vector<vector<char>> v(n, vector<char>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    vector<vector<int>> dist(n, vector<int>(n, -1));
    dist[a][b] = 0;
    queue<pair<int, int>> q;
    q.push({a, b});
    while(!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for(int k = 1; k < n; k++) {
            int x = a + k;
            int y = b + k;
            if(x < 0 || y < 0 || x >= n || y >= n) break;
            if(v[x][y] == '#') break;
            if(dist[x][y] == -1) {
                dist[x][y] = dist[a][b] + 1;
                q.push({x, y});
                continue;
            }
            if(dist[x][y] <= dist[a][b]) break;
        }
        for(int k = 1; k < n; k++) {
            int x = a + k;
            int y = b - k;
            if(x < 0 || y < 0 || x >= n || y >= n) break;
            if(v[x][y] == '#') break;
            if(dist[x][y] == -1) {
                dist[x][y] = dist[a][b] + 1;
                q.push({x, y});
                continue;
            }
            if(dist[x][y] <= dist[a][b]) break;
        }
        for(int k = 1; k < n; k++) {
            int x = a - k;
            int y = b + k;
            if(x < 0 || y < 0 || x >= n || y >= n) break;
            if(v[x][y] == '#') break;
            if(dist[x][y] == -1) {
                dist[x][y] = dist[a][b] + 1;
                q.push({x, y});
                continue;
            }
            if(dist[x][y] <= dist[a][b]) break;
        }
        for(int k = 1; k < n; k++) {
            int x = a - k;
            int y = b - k;
            if(x < 0 || y < 0 || x >= n || y >= n) break;
            if(v[x][y] == '#') break;
            if(dist[x][y] == -1) {
                dist[x][y] = dist[a][b] + 1;
                q.push({x, y});
                continue;
            }
            if(dist[x][y] <= dist[a][b]) break;
        }
    }
    cout << dist[c][d];
    return 0;
}