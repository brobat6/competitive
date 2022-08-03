#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    vector<vector<vector<pair<int, int>>>> a(n, vector<vector<pair<int, int>>>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i; j++) {
            if(i == 0 && j == 0) {
                a[i][j].push_back({v[i][j], 1});
            } else {
                map<int, int> x;
                if(i > 0) {
                    for(auto y : a[i - 1][j]) {
                        x[y.first ^ v[i][j]] += y.second;
                    }
                }
                if(j > 0) {
                    for(auto y : a[i][j - 1]) {
                        x[y.first ^ v[i][j]] += y.second;
                    }
                }
                for(auto y : x) {
                    a[i][j].push_back(y);
                }
            }
        }
    }
    vector<vector<vector<pair<int, int>>>> b(n, vector<vector<pair<int, int>>>(m));
    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; )
    }

    
    return 0;
}