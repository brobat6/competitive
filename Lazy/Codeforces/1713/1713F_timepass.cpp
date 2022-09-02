#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> b(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        cin >> b[0][i];
    }
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            b[i][j] = b[i - 1][j] ^ b[i][j - 1];
        }
    }
    for(int i = 0; i < n; i++) {
        cout << b[i][n - 1] << ' ';
    }

    return 0;
}