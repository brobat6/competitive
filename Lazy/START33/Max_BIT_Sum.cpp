#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> a(n), b(n);
        int ones = 0;
        int zeros = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] == 0) zeros++;
            if(a[i] == 1) ones++;
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        int x[25][25]; // table for array a.
        int y[20]; // count of values between 2^i and 2^(i + 1) - 1
        int z[20]; // count of values with i^th bit set.
        for(int i = 0; i < 20; i++) {
            for(int j = 0; j < 20; j++) {
                x[i][j] = 0;
            }
            y[i] = 0;
            z[i] = 0;
        }
        for(int i = 0; i < n; i++) {
            int k = 0;
            for(int j = 0; j < 20; j++) {
                if((a[i] >> j) & 1) {
                    // x[i][j]++;
                    z[j]++;
                    k = j;
                }
            }
            y[k]++;
            for(int j = 0; j < 20; j++) {
                if((a[i] >> j) & 1) {
                    x[k][j]++;
                }
            }
        }
        // for(int i = 0; i < 5; i++) {
        //     for(int j = 0; j < 5; j++) {
        //         cout << x[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int k = 0;
            for(int j = 0; j < 20; j++) {
                if((b[i] >> j) & 1) {
                    k = j;
                }
            }
            if(b[i] == 0) ans += ones;
            if(b[i] == 1) ans += zeros;
            for(int j = 0; j < 20; j++) {
                if((b[i] >> j) & 1) {
                    ans += (1<<j) * (n - z[j] - y[k] + x[k][j]); // 0s in other cohorts, XOR
                    ans += (1<<j) * x[k][j]; // 1s in current cohort, AND
                } else {
                    ans += (1<<j) * (z[j] - x[k][j]);
                }
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}