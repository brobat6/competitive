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
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        const int INF = (int)1E18;
        // vector <int> benefit(n, -INF);
        // benefit[0] = 0;
        // benefit[1] = v[1] % v[0] - v[1];
        // benefit[1] = 0;
        // for(int i = 2; i < n; i++) {
        //     for(int j = 1; j < i; j++) {
        //         // mx = max(mx, )
        //         int x = v[i];
        //         int y = v[j];
        //         benefit[i] = max(benefit[i], benefit[j] - x%v[0] - y + x%y + y%v[0]);
        //     }
        // }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += (v[i] % v[(i + 1) % n]);
        }
        // cout << ans + (*max_element(benefit.begin(), benefit.end())) << '\n';
        
        int benefit[n][n];



        // benefit[x][y] --> Benefit of replacing x - lowest - ... y with x - y - lowest - ....
        // = x % lowest + y - (x % y + y % lowest).
        // benefit[0][x] --> ignore!!! 
        // x > y for replacement.


        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) {
        //         benefit[i][j] = -(int)1E18;
        //     }
        // }

        for(int i = 1; i < n; i++) {
            for(int j = 1; j < i; j++) {
                if(i == j) continue;
                int x = v[i];
                int y = v[j];
                benefit[i][j] = - x%v[0] - y + x%y + y%v[0];
                // cout << benefit[i][j] << " ";
            }
            // cout << '\n';
        }
        if(n <= 2) {
            cout << ans << endl;
            continue;
        }
        vector <int> b(n, 0);
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < i; j++) {
                b[i] = max(b[i], b[j] + benefit[i][j]);
            }
        }
        // for(int i = 0; i < n; i++) {
            // cout << b[i] << " ";
        // }
        // cout << endl;
        cout << ans + b[n - 1] << endl;
        // cout << accumulate(v.begin(), v.end(), 0ll) - (*max_element(b.begin(), b.end())) << '\n';

        // cout << ans << '\n';
        

    }

    
    return 0;
}