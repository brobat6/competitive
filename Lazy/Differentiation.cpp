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
        vector <int> sum(n, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> v[i][j];
                sum[i] += v[i][j];
            }
        }
        int mx = 0;
        for(int i = 0; i < m; i++) {
            vector <int> nv;
            for(int j = 0; j < n; j++) {
                nv.push_back(m * v[j][i] - sum[j]);
            }
            int x = 0;
            int y = 0;
            for(int j = 0; j < n; j++) {
                if(nv[j] > 0) x += nv[j];
                else y -= nv[j];
            }
            mx = max(x, mx);
            mx = max(y, mx);
        }
        cout << mx << '\n';
    }
    
    return 0;
}