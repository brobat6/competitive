#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int r, c;
    cin >> r >> c;
    int x[2][2];
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            cin >> x[i][j];
        }
    }
    cout << x[r - 1][c - 1];
    
    return 0;
}