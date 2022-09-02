#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int x = 0;
    int y = 0;
    while(true) {
        if(vis[x][y]) {
            cout << -1;
            return 0;
        }
        vis[x][y] = true;
        if(grid[x][y] == 'U') {
            if(x > 0) {
                x--;
            } else {
                break;
            }
        }
        if(grid[x][y] == 'D') {
            if(x < n - 1) {
                x++;
            } else {
                break;
            }
        }
        if(grid[x][y] == 'L') {
            if(y > 0) {
                y--;
            } else {
                break;
            }
        }
        if(grid[x][y] == 'R') {
            if(y < m - 1) {
                y++;
            } else {
                break;
            }
        }
    }
    cout << x + 1 << ' ' << y + 1 << '\n';
    
    return 0;
}