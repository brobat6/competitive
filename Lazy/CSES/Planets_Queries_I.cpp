#include <bits/stdc++.h>
using namespace std;

int up[200100][31];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    int l = 31;
    for(int i = 0; i < n; i++) {
        cin >> up[i][0];
        --up[i][0];
    }
    for(int i = 1; i < l; i++) {
        for(int j = 0; j < n; j++) {
            up[j][i] = up[up[j][i - 1]][i - 1];
        }
    }
    for(int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;
        --x;
        int y = x;
        for(int j = 0; j < l; j++) {
            if((k >> j) & 1) {
                y = up[y][j];
            }
        }
        cout << y + 1 << '\n';
    }
    
    return 0;
}