#include <bits/stdc++.h>
using namespace std;

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

int r, c;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char key[4] = {'E', 'S', 'W', 'N'};
int g[405][405];
int vis[405][405];
char z[405][405];

bool yyy;

void F(int x, int y, int dx, int dy) {
    // cerr << x << " " << y << '\n';
    vis[x][y] = 1;
    for(int k = 0; k < 4; k++) {
        int a = x + dir[k][0];
        int b = y + dir[k][1];
        if(a < 0 || b < 0 || a >= 2*r || b >= 2*c) continue;

        if(a == dx && b == dy) {
            z[x][y] = key[k];
            return;
        }

        if(g[a][b] == 1) continue;
        if(vis[a][b] == 1) continue;
        z[x][y] = key[k];
        F(a, b, dx, dy);
        break;
    }
}

void solve() {
    
    cin >> r >> c;
    yyy = true;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            char x; cin >> x;
            int y = (x == '*' ? 0 : 1);
            g[2*i][2*j] = g[2*i + 1][2*j] = g[2*i][2*j + 1] = g[2*i + 1][2*j + 1] = y;
            if(y == 1) {
                vis[2*i][2*j] = vis[2*i + 1][2*j] = vis[2*i][2*j + 1] = vis[2*i + 1][2*j + 1] = 1;
            } else {
                vis[2*i][2*j] = vis[2*i + 1][2*j] = vis[2*i][2*j + 1] = vis[2*i + 1][2*j + 1] = 0;
            }
        }
    }

    

    bool pos = true;
    {
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = -1;
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int k = 0; k < 4; k++) {
                int a = x + dir[k][0];
                int b = y + dir[k][1];
                if(a < 0 || b < 0 || a >= 2*r || b >= 2*c) continue;
                if(vis[a][b] == 1) continue;
                if(vis[a][b] == 0) {
                    vis[a][b] = -1;
                    q.push({a, b});
                }
            }
        }
        for(int i = 0; i < 2*r; i++) {
            for(int j = 0; j < 2*c; j++) {
                if(vis[i][j] == 0) {
                    pos = false;
                }
                if(vis[i][j] == -1) {
                    vis[i][j] = 0;
                }
            }
        }
    }
    
    if(!pos) {
        cout << "IMPOSSIBLE\n";
        return;
    }


    int x = 0;
    int y = 0;
    vis[x][y] = 1;
    string ans;

    for(int i = 0; i < 2*r; i++) {
        for(int j = 0; j < 2*c; j++) {
            z[i][j] = '0';
        }
    }

    map<char, pair<int, int>> move;
    for(int k = 0; k < 4; k++) {
        move[key[k]] = {dir[k][0], dir[k][1]};
        // cout << move[key[k]].first << " " << move[key[k]].second << " " << key[k] << '\n';
    }

    while(true) {
        bool pos = false;
        for(int k = 0; k < 4; k++) {
            int a = x + dir[k][0];
            int b = y + dir[k][1];
            if(a < 0 || b < 0 || a >= 2*r || b >= 2*c) continue;
            if(g[a][b] == 1) continue;
            if(a == 0 && b == 0) {
                ans += key[k]; 
                z[x][y] = key[k];
                break;
            }
            if(vis[a][b] == 1) continue;
            vis[a][b] = 1;
            ans += key[k];
            z[x][y] = key[k];
            x = a;
            y = b;
            pos = true;
            break;
        }
        if(!pos) break;
    }

    x = 0;
    y = 0;

    ans.clear();
    bool xxx = true;
    while(true) {
        // cout << x << " " << y << " " << z[x][y] << '\n';
        for(int k = 0; k < 4; k++) {
            int dx = x + move[z[x][y]].first;
            int dy = y + move[z[x][y]].second;
            int a = x + dir[k][0];
            int b = y + dir[k][1];
            if(a < 0 || b < 0 || a >= 2*r || b >= 2*c) continue;
            if(g[a][b] == 1 || vis[a][b] == 1) continue;
            z[x][y] = key[k];
            // cout << x << " " << y << " " << k << " hm\n";
            F(a, b, dx, dy);
        }
        if(z[x][y] == '0') {
            xxx = false;
            break;
        }
        ans += z[x][y];
        int ta = move[z[x][y]].first;
        int tb = move[z[x][y]].second;
        x += ta; y += tb;
        if(x == 0 && y == 0) break;
    }
    if(!xxx) cout << "IMPOSSIBLE\n";
    else cout << ans << '\n';
    // for(int i = 0; i < 2*r; i++) {
    //     for(int j = 0; j < 2*c; j++) {
    //         cout << (g[i][j] == 0 ? '*' : '#');
    //         // cout << z[i][j];
    //     }
    //     cout << '\n';
    // }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    for(int I = 1; I <= t; I++) {
        cout << "Case #" << I << ": ";
        solve();
    }
    
    return 0;
}