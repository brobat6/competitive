#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    int e[n][n];
    memset(e, 0, sizeof(e));
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        e[x][y] = e[y][x] = 1;
    }
    int ans = 0;
    for(int a = 0; a < n; a++) {
        for(int b = a + 1; b < n; b++) {
            for(int c = b + 1; c < n; c++) {
                if(e[a][b] && e[b][c] && e[c][a]) ans++;
            }
        }
    }
    cout << ans;

    return 0;
}