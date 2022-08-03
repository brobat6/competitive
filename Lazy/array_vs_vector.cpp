#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int F[n + 1][m + 1];
        memset(F, 0, sizeof(F));
        // vector<vector<int>> F(n + 1, vector<int>(m + 1, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                F[i + 1][j + 1] = F[i + 1][j] + F[i][j + 1] - F[i][j] + matrix[i][j];
            }
        }
        int ans = 0;
        for(int c = 1; c <= n; c++) {
            for(int d = 1; d <= m; d++) {
                for(int a = 0; a < c; a++) {
                    for(int b = 0; b < d; b++) {
                        int x = F[c][d] - F[c][b] - F[a][d] + F[a][b];
                        if(x == target) ans++;
                    }
                }
            }
        }
        return ans;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    Solution s;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> x(n, vector<int>(m));
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            x[i][j] = rng() % 1000 - 500;
        }
    }
    cout << s.numSubmatrixSumTarget(x, 0);

    return 0;
}