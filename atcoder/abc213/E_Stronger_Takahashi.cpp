#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 520
#define MOD 1000000007

int h, w;
char arr[MAXN][MAXN];
int dp[MAXN][MAXN];

vector <pair<int, int>> a1;
vector <pair<int, int>> a2;

void bfs(pair<int, int> start) {
    queue<pair<int, int>> q;
    dp[start.first][start.second] = 0;
    q.push(start);
    while(!q.empty()) {
        auto v = q.front();
        int curr = dp[v.first][v.second];
        q.pop();
        for(auto k : a1) {
            int x = v.first + k.first;
            int y = v.second + k.second;
            if(x<0||x>=h||y<0||y>=w) continue;
            if(dp[x][y] > curr + 1) {
                dp[x][y] = curr + 1;
                q.push({x, y});
            }
        }
        for(auto k : a2) {
            int x = v.first + k.first;
            int y = v.second + k.second;
            if(x<0||x>=h||y<0||y>=w) continue;
            if(arr[x][y]=='#' && dp[x][y] > curr + 1) {
                dp[x][y] = curr + 1;
                q.push({x, y});
            }
            if(arr[x][y]=='.' && dp[x][y] > curr) {
                dp[x][y] = curr;
                q.push({x, y});
            }
        }
    }
}

void pre() {
    forn(i, -2, 3) {
        if(i==-2||i==2) {
            forn(j, -1, 2) a1.push_back({i, j});
        }
        else if(i==-1||i==1) {
            forn(j, -2, 3) a1.push_back({i, j});
        }
        else {
            forn(j, -2, 3) {
                if(j==0) continue;
                a1.push_back({i, j});
            }
        }
    }
    a2.push_back({1, 0});
    a2.push_back({-1, 0});
    a2.push_back({0, 1});
    a2.push_back({0, -1});
    forn(i, 0, h) {
        forn(j, 0, w) {
            dp[i][j] = MOD;
        }
    }
}

void out() {
    // forn(i, 0, h) {
    //     forn(j, 0, w) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[h-1][w-1];
}

void solve() {
    cin >> h >> w;
    pre();
    forn(i, 0, h) {
        forn(j, 0, w) {
            cin >> arr[i][j];
        }
    }
    bfs({0, 0});
    out();
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // int t; cin >> t; while(t--)
    {solve();}
    return 0;
}