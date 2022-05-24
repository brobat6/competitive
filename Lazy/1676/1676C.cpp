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
        vector<string> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int ans = (int)1E18;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int temp = 0;
                for(int k = 0; k < m; k++) {
                    temp += abs((int)(v[i][k] - v[j][k]));
                }
                ans = min(ans, temp);
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}