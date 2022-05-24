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
        vector<vector<int>> v(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> v[i][j];
            }
        }
        vector <int> f(n + m + 5, 0);
        vector <int> g(n + m + 5 + n + m, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                f[i + j] += v[i][j];
                g[i - j + m] += v[i][j];
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans, f[i + j] + g[i - j + m] - v[i][j]);
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}