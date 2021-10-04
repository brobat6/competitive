#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 1000;
const int MOD = 1000000007;

char arr[MAXN][MAXN];
bool visited[MAXN][MAXN];
int n, m, ans;
int e[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    visited[x][y] = true;
    q.push({x, y});
    while(!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        forn(i, 0, 4) {
            int c = a + e[i][0];
            int d = b + e[i][1];
            if(c<0||d<0||c>=n||d>=m) continue;
            if(arr[c][d]=='.' && !visited[c][d]) {
                visited[c][d] = true;
                q.push({c, d});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    forn(i, 0, n) forn(j, 0, m) cin >> arr[i][j];
    ans = 0;
    forn(i, 0, n) forn(j, 0, m) {
        if(!visited[i][j] && arr[i][j]=='.') {
            bfs(i, j);
            ans++;
        }
    }
    cout << ans << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}