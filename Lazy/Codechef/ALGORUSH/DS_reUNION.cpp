#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int adj[n][n];
        memset(adj, 0, sizeof(adj));
        for(int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            adj[x][y] = 1;
            adj[y][x] = 1;
        }
        vector <int> e(1<<n, 0);
        for(int i = 1; i < (1<<n); i++) {
            int cnt = __builtin_popcount(i);
            if(cnt <= 1) {
                e[i] = 0;
                continue;
            }
            int stor = -1;
            for(int j = 0; j < n; j++) {
                if((i >> j) & 1) {
                    if(stor == -1) {
                        stor = j;
                        break;
                    }
                }
            }
            int ans = e[i - (1<<stor)];
            for(int j = 0; j < n; j++) {
                if((i >> j) & 1) {
                    if(j == stor) continue;
                    ans += adj[stor][j] == 1;
                }
            }
            e[i] = ans;
        }
        int ans = 0;
        for(int i = 1; i < (1<<n); i++) {
            int x = __builtin_popcount(i);
            if(e[i] == x * (x - 1)/2) {
                ans = max(ans, x);
            }
            // cout << i << " " << e[i] << '\n';
        }
        cout << ans << '\n';
    }
    
    return 0;
}