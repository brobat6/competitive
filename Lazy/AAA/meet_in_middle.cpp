#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    


    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector <pair<int, int>> f[n][m]; // {sum, num}
    vector <pair<int, int>> A[n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m/2; j++) {
            if(i == 0 && j == 0) {
                f[i][j].push_back({grid[i][j], 1});
            } else {
                map <int, int> x;
                if(i > 0) {
                    for(auto a : f[i - 1][j]) {
                        x[(a.first + grid[i][j]) % k] += a.second;
                    }
                }
                if(j > 0) {
                    for(auto a : f[i][j - 1]) {
                        x[(a.first + grid[i][j]) % k] += a.second;
                    }
                }
                for(auto a : x) {
                    f[i][j].push_back(a);
                }
            }
        }
        A[i] = f[i][m/2 - 1];
        if(i > 0) {
            for(int j = 0; j < m/2; j++) {
                f[i - 1][j].clear();
            }
        }
    }

    // for(auto i : A) {
    //     for(auto j : i) {
    //         cout << "{" << j.first << "," << j.second << "} ";
    //     }
    //     cout << '\n';
    // }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            f[i][j].clear();
        }
    }

    // now solve for m/2 to m - 1
    vector <pair<int, int>> B[n];
    
    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= m/2; j--) {
            if(i == n - 1 && j == m - 1) {
                f[i][j].push_back({grid[i][j], 1});
            } else {
                map <int, int> x;
                if(i < n - 1) {
                    for(auto a : f[i + 1][j]) {
                        x[(a.first + grid[i][j]) % k] += a.second;
                    }
                }
                if(j < m - 1) {
                    for(auto a : f[i][j + 1]) {
                        x[(a.first + grid[i][j]) % k] += a.second;
                    }
                }
                for(auto a : x) {
                    f[i][j].push_back(a);
                }
            }
        }
        B[i] = f[i][m/2];
        if(i < n - 1) {
            for(int j = m/2; j < m; j++) {
                f[i + 1][j].clear();
            }
        }
    }

    // for(auto i : B) {
    //     for(auto j : i) {
    //         cout << "{" << j.first << "," << j.second << "} ";
    //     }
    //     cout << '\n';
    // }

    // now find answer.

    int ans = 0;

    for(int i = 0; i < n; i++) {
        map<int, int> m;
        for(auto j : A[i]) {
            m.insert(j);
        }
        for(auto j : B[i]) {
            if(m.find((k - j.first) % k) != m.end()) {
                ans += m[(k - j.first) % k] * j.second;
            }
        }
    }
    
    cout << ans;

    // clock_t start = clock();



    // clock_t end = clock();
    
    // cout << (double)(end - start)/CLOCKS_PER_SEC << '\n';
    
    return 0;
}