#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int d[n][n][n];
        // d[i][j][k] --> d(i, k) == d(j, k).
        memset(d, 0, sizeof(d));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n - i; j++) {
                for(int k = 1; k <= n; k++) {
                    char c;
                    cin >> c;
                    if(c == '1') {
                        d[i - 1][i - 1 + j - 1][k - 1] = 1;
                        d[i - 1 + j - 1][i - 1][k - 1] = 1;
                    }
                }
            }
        }
        
    }
    
    return 0;
}