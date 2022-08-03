#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    int l = ceil(log2(n)) + 1;
    vector<vector<int>> up(n, vector<int>(l, -1));
    up[0][0] = -2;
    for(int i = 1; i < n; i++) {
        cin >> up[i][0];
        --up[i][0];
    }
    for(int i = 1; i < l; i++) {
        for(int j = 0; j < n; j++) {
            if(up[j][i - 1] == -2) up[j][i] = -2;
            else up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }
    for(int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;
        --x;
        int y = x;
        for(int j = 0; j < l; j++) {
            if(k % 2) {
                y = up[y][j];
            }
            if(y == -2) break;
            k >>= 1;
        }
        cout << y + 1 << '\n';
    }
    
    return 0;
}