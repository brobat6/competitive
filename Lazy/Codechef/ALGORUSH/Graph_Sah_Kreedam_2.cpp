#include <bits/stdc++.h>
using namespace std;
#define int long long

const int L = 31;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector <int> pw(L);
    pw[0] = 1;
    for(int i = 1; i < L; i++) {
        pw[i] = pw[i - 1] * 2;
    }
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> nx(n, vector<int>(L)); // 2^L th successor.

    for(int i = 0; i < n; i++) {
        cin >> nx[i][0];
        --nx[i][0];
    }
    for(int j = 1; j < L; j++) {
        for(int i = 0; i < n; i++) {
            nx[i][j] = nx[nx[i][j - 1]][j - 1];
        }
    }

    for(int i = 0; i < m; i++) {
        int x, k;
        cin >> x >> k;
        --x;
        int ans = x;
        for(int j = 0; j < L; j++) {
            if((k >> j) & 1) {
                ans = nx[ans][j];
            }
        }
        cout << ans + 1 << '\n';
    }
    
    return 0;
}