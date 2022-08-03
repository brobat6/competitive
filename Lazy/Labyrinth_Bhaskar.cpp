#include <bits/stdc++.h>

using namespace std;

queue<pair<int, int>> q;

int main() {
    int n, m;
    cin >> n >> m;
    pair<int, int> start;
    pair<int, int> end;
    vector<vector<char>> parent;

    int maze[n][m];
    for (int i = 0; i < n; i++) {
        vector<char> temp;
        for (int j = 0; j < m; j++) {
            temp.push_back('#');
            char ele;
            cin >> ele;
            maze[i][j] = ele;
            if (ele == 'A') {
                start = {i, j};
            }

            else if (ele == 'B') {
                end = {i, j};
            }
        }
        parent.push_back(temp);
    }

    parent[start.first][start.second] = 'O';
    q.push(start);

    while (!q.empty()) {
        pair<int, int> current;
        current = q.front();
        int x = current.first;
        int y = current.second;

        // (x, y).

        //cout << current.first << " " << current.second << endl;

        if (maze[x][y] == 'B') {
            break;
        }

        if (x > 0 && maze[x-1][y] != '#' && parent[x-1][y] == '#') {
            parent[x-1][y] = 'U';
            q.push({x-1, y});
        }

        if (x < n-1 && maze[x+1][y] != '#' && parent[x+1][y] == '#') {
            parent[x+1][y] = 'D';
            q.push({x+1, y});
        }

        if (y > 0 && maze[x][y-1] != '#' && parent[x][y-1] == '#') {
            parent[x][y-1] = 'L';
            q.push({x, y-1});
        }

        if (y < m-1 && maze[x][y+1] != '#' && parent[x][y+1] == '#') {
            parent[x][y+1] = 'R';
            q.push({x, y+1});
        }
        q.pop();
    
    }

    if (parent[end.first][end.second] == '#') {
        cout << "NO" << endl;
        return 0;
    }

    else {
        cout << "YES" << endl;
        vector<char> path;
        pair<int, int> current = end;
        while(parent[current.first][current.second] != 'O') {
            int x = current.first;
            int y = current.second;
            char dir = parent[x][y];
            path.push_back(dir);
            if (dir == 'U') {
                current.first += 1;
            }

            if (dir == 'D') {
                current.first -= 1;
            }
            
            if (dir == 'L') {
                current.second += 1;
            }
            
            if (dir == 'R') {
                current.second -= 1;
            }
            
        }
        reverse(path.begin(), path.end());
        cout << path.size() << endl;

        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
        }
        cout << endl;
    }



}