#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[12][12][25][1029];
const int INF = (int)5E18;

// North, East, West, South.
char oper[4];
int func[4];
int dir[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

int op(int x, int d) {
    if(oper[d] == '+') return x + func[d];
    if(oper[d] == '-') return x - func[d];
    if(oper[d] == '*') return x * func[d];
    // divide by negative!!.
    int y = x / func[d];
    while(y * func[d] > x) y--;
    return y;
}

void solve() {
    int n, p, m, ax, ay;
    cin >> n >> p >> m >> ax >> ay;
    --ax; --ay;
    for(int i = 0; i < 4; i++) {
        cin >> oper[i] >> func[i];
    }
    map<pair<int, int>, pair<int, int>> c; // c[{x, y}] = {customer_id, cost paid}.
    for(int i = 0; i < p; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        --x; --y;
        c[{x, y}] = {i, z};
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k <= m; k++) {
                for(int l = 0; l < (1<<p); l++) {
                    dp[i][j][k][l] = -INF;
                }
            }
        }
    }
    dp[ax][ay][0][0] = 0;
    for(int k = 0; k <= m; k++) {
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < n; i++) {
                for(int l = 0; l < (1<<p); l++) {
                    if(dp[i][j][k][l] == -INF) continue;
                    if(c.find({i, j}) != c.end()) {
                        auto x = c[{i, j}];
                        if(((l >> x.first) & 1) == 0) {
                            dp[i][j][k][l|(1<<x.first)] = max(dp[i][j][k][l|1<<x.first], dp[i][j][k][l] + x.second);
                        }
                    }
                    dp[i][j][k + 1][l] = max(dp[i][j][k][l], dp[i][j][k + 1][l]);
                    for(int d = 0; d < 4; d++) {
                        int x = i + dir[d][0];
                        int y = j + dir[d][1];
                        if(x < 0 || y < 0 || x >= n || y >= n) continue;
                        dp[x][y][k + 1][l] = max(dp[x][y][k + 1][l], op(dp[i][j][k][l], d));
                    }
                }
            }
        }
    }
    // for(int k = 0; k <= m; k++) {
    //     for(int i = 0; i < n; i++) {
    //         for(int j = 0; j < n; j++) {
    //             for(int l = 0; l < (1<<p); l++) {
    //                 cerr << k << ' ' << i + 1 << ' ' << j + 1 << ' ' << l << ' ' << dp[i][j][k][l] << '\n';
    //             }
    //         }
    //     }
    // }
    int ans = -INF;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans = max(ans, dp[i][j][m][(1<<p) - 1]);
        }
    }
    if(ans == -INF) cout << "IMPOSSIBLE\n";
    else cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        cout << "Case #" << I << ": ";
        solve();
    }
    
    return 0;
}