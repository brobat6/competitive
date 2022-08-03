#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int wt[n][n];
        int sum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> wt[i][j];
                sum += wt[i][j];
            }
        }
        sum /= 2;

        int mb = n - k;
        int m = 1<<(n - k);

        int pop[m]; // builtin-popcount O(1)
        for(int i = 0; i < m; i++) pop[i] = __builtin_popcount(i);    

        int ss[k][m]; // weight for the component, assuming the only special city is k

        // (3, 4, 5, 6)
        // special - (1, 2)
        // 1 ---> (3), (4), (3, 4), (3, 5) .... (3, 4, 5, 6)
        // 2 ---> ....

        // (3, 4, 5, 6) 
        // Cities 1 and 2
        // City 3 
        // City 4
        // 3^n --> k
        // 3^(n - k) * k
        
        for(int i = 0; i < k; i++) {
            ss[i][0] = 0;
            for(int j = 1; j < m; j++) {
                int first = -1;
                for(int t = 0; t < mb; t++) {
                    if((j >> t) & 1) {
                        first = t;
                        break;
                    }
                }
                assert(first != -1);
                int prev = j - (1<<first);
                ss[i][j] = ss[i][prev];
                ss[i][j] += wt[k + first][i];
                for(int t = 0; t < mb; t++) {
                    if((j >> t) & 1) {
                        ss[i][j] += wt[k + first][k + t];
                    }
                }
            }
        }

        // for(int i = 0; i < k; i++) {
        //     for(int j = 0; j < m; j++) {
        //         cout << ss[i][j] << " ";
        //     }
        //     cout << '\n';
        // }

        // cout << '\n';

        int dp[1<<(n - k)]; // run for k iterations, maximise the weight on including special city k at each iteration
        memset(dp, 0, sizeof(dp));

        for(int it = 0; it < k; it++) {
            int ndp[1<<(n - k)];
            memset(ndp, 0, sizeof(ndp));
            for(int j = 0; j < m; j++) {
                for(int s = j; ; s = (s - 1) & j) {
                    // using dp[s], maximise ndp[j]
                    ndp[j] = max(ndp[j], dp[s] + ss[it][s ^ j]);
                    if(s == 0) break;
                }
            }
            for(int j = 0; j < m; j++) {
                dp[j] = ndp[j];
                // cout << dp[j] << " ";
            }
            // cout << '\n';
        }
        cout << sum - dp[m - 1] << '\n';
    }
    
    return 0;
}
