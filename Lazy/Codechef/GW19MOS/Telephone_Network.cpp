#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = (int)1E18;

inline int dist(pair <int, int> &a, pair<int, int> &b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

struct S {
    int x, y, d;

    bool operator <(const S& other) const {
        return d > other.d;
    }
};

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int grid[n][n];
        int dp[n][n];
        vector<vector<pair<int, int>>> v(k);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> grid[i][j];
                --grid[i][j];
                v[grid[i][j]].push_back({i, j});
                if(grid[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = INF;
                }
            }
        }
        for(int i = 1; i < k; i++) {
            if((int)v[i - 1].size() * (int)v[i].size() < n) {
                for(auto p : v[i - 1]) {
                    for(auto q : v[i]) {
                        dp[q.first][q.second] = min(dp[q.first][q.second], dp[p.first][p.second] + dist(p, q));
                    }
                }
            } else {
                int d[n][n];
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < n; j++) {
                        d[i][j] = INF;
                    }
                }
                priority_queue <S> pq;
                for(auto p : v[i - 1]) {
                    d[p.first][p.second] = dp[p.first][p.second];
                    pq.push({p.first, p.second, d[p.first][p.second]});
                }
                while(!pq.empty()) {
                    S temp = pq.top();
                    pq.pop();
                    int a = temp.x;
                    int b = temp.y;
                    int temp_dist = temp.d;
                    if(d[a][b] != temp_dist) continue;
                    for(int k = 0; k < 4; k++) {
                        int x = a + dir[k][0];
                        int y = b + dir[k][1];
                        if(x < 0 || y < 0 || x >= n || y >= n) continue;
                        if(d[x][y] > d[a][b] + 1) {
                            d[x][y] = d[a][b] + 1;
                            pq.push({x, y, d[x][y]});
                        }
                    }
                }
                for(auto p : v[i]) {
                    dp[p.first][p.second] = d[p.first][p.second];
                }
            }
        }
        int ans = INF;
        for(auto p : v[k - 1]) {
            ans = min(ans, dp[p.first][p.second]);
        }
        cout << ans << '\n';
    }
    
    return 0;
}