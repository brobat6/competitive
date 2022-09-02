#include <bits/stdc++.h>
using namespace std;

const int N = 3005;
char grid[N][N];
bool dead[N][N]; // true for rocks and dead-ends.
int n, m;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool check(int i, int j) {
    // check if {x, y} is a dead-end or not.
    if(grid[i][j] == '#') return true;
    int cnt = 0; // count number of available neighbours, that COULD be filled with trees.
    for(int k = 0; k < 4; k++) {
        int x = i + dir[k][0];
        int y = j + dir[k][1];
        if(x < 0 || x >= n || y < 0 || y >= m || dead[x][y]) continue;
        cnt++;
    }
    return cnt < 2;
}

void solve() {
    cin >> n >> m;
    int count_trees = 0;
    memset(dead, false, sizeof(dead));
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == '#') {
                dead[i][j] = true;
                q.push({i, j});
            }
            if(grid[i][j] == '^') {
                count_trees++;
            }
        }
    }
    if(count_trees == 0) {
        cout << "Possible" << '\n';
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << grid[i][j];
            }
            cout << '\n';
        }
        return;
    }
    if(min(n, m) == 1) {
        cout << "Impossible" << '\n';
        return;
    }
    while(!q.empty()) {
        auto [a, b] = q.front();
        q.pop();
        for(int k = 0; k < 4; k++) {
            int x = a + dir[k][0];
            int y = b + dir[k][1];
            if(x < 0 || x >= n || y < 0 || y >= m || dead[x][y]) continue;
            if(check(x, y)) {
                dead[x][y] = true;
                q.push({x, y});
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '^' && dead[i][j]) {
                cout << "Impossible" << '\n';
                return;           
            }
        }
    }
    cout << "Possible" << '\n';
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(dead[i][j]) cout << grid[i][j];
            else cout << '^';
        }
        cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    freopen("second_second_friend_input.txt", "r", stdin);
    freopen("second_second_friend_output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        cout << "Case #" << I << ": ";
        solve();
    }
    
    return 0;
}