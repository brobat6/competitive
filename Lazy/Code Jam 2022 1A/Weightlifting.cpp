#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int INF = 1E18;

void solve() {
    int n, w;
    cin >> n >> w;
    vector<vector<int>> wt(n, vector<int>(w));
    vector<int> ht(n, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < w; j++) {
            cin >> wt[i][j];
            ht[i] += wt[i][j];
        }
    }
    vector<vector<int>> x(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        vector <int> t = wt[i];
        int sum = accumulate(t.begin(), t.end(), 0ll);
        for(int j = i + 1; j < n; j++) {
            for(int k = 0; k < w; k++) {
                if(wt[j][k] < t[k]) {
                    sum -= (t[k] - wt[j][k]);
                    t[k] = wt[j][k];
                }
            }
            x[i][j] = sum;
        }
    }
    vector<vector<int>> dp(n, vector<int>(n, INF));
    for(int i = 0; i < n; i++) {
        dp[i][i] = ht[i];
    }
    // dp[i][j] --> Cost of building i from scratch and building upto j.
    for(int d = 1; d < n; d++) {
        // d --> difference
        for(int i = 0; i < n - k; i++) {
            int j = i + d;
            for(int k = i; k <= j; k++) {
                // minimise dp[i][j] based on dp[i][k] and dp[k][j].
                
            }
        }
    }
}

// int transition(string &a, string &b) {
//     int n = a.length();
//     int m = b.length();
//     int ans = n + m;
//     for(int i = 0; i < min(n, m); i++) {
//         if(a[i] == b[i]) {
//             ans -= 2;
//         } else {
//             break;
//         }
//     }
//     return ans;
// }

// void solve() {
//     int n, w;
//     cin >> n >> w;
//     vector<vector<int>> wt(n, vector<int>(w));
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < w; j++) {
//             cin >> wt[i][j];
//         }
//     }
//     vector<vector<string>> v(n);
//     for(int i = 0; i < n; i++) {
//         string s;
//         for(int j = 0; j < w; j++) {
//             for(int k = 0; k < wt[i][j]; k++) {
//                 s += ('A' + j);
//             }
//         }
//         do {
//             v[i].push_back(s);
//         } while(next_permutation(s.begin(), s.end()));
//     }
//     vector<vector<int>> dp(n);
//     dp[0].resize((int)v[0].size(), 0);
//     for(int i = 1; i < n; i++) {
//         dp[i].resize((int)v[i].size(), INF);
//         int x = (int)v[i - 1].size();
//         int y = (int)v[i].size();
//         for(int a = 0; a < x; a++) {
//             for(int b = 0; b < y; b++) {
//                 dp[i][b] = min(dp[i][b], dp[i - 1][a] + transition(v[i - 1][a], v[i][b]));
//             }
//         }
//     }
//     int x = *min_element(dp[n - 1].begin(), dp[n - 1].end());
//     for(int i = 0; i < w; i++) {
//         x += wt[0][i];
//         x += wt[n - 1][i];
//     }
//     cout << x << endl;
// }

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    
    return 0;
}