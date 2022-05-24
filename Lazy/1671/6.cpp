#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int z[12][12][11];
    memset(z, 0, sizeof(z));

    for(int n = 1; n <= 10; n++) {
        // int n = 11;
        vector<int> v(n);
        for(int i = 0; i < n; i++) v[i] = i + 1;
        vector<vector<int>> ans(12, vector<int>(12, 0)); // number of values with  k = i and x = j.
        do {
            int x = 0;
            int k = 0;
            for(int i = 0; i < n - 1; i++) {
                if(v[i] > v[i + 1]) x++;
                for(int j = i + 1; j < n; j++) {
                    if(v[i] > v[j]) k++;
                }
            }
            if(x <= 11 && k <= 11) {
                ans[k][x]++;
            }
        } while(next_permutation(v.begin(), v.end()));
        // cout << "For n = " << n << '\n';
        // for(int i = 0; i < 12; i++) {
        //     cout << "When k = " << i << ": ";
        //     for(int j = 0; j < 12; j++) {
        //         cout << ans[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        for(int i = 0; i < 12; i++) {
            for(int j = 0; j < 12; j++) {
                z[i][j][n] = ans[i][j];
            }
        }
    }
    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 12; j++) {
            cout << "For k = " << i << " and x = " << j << ": ";
            for(int n = 1; n <= 10; n++) {
                cout << z[i][j][n] << " ";
            }
            cout << '\n';
        }
    }
    
    return 0;
}