#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector <int> a(105, 0), b(105, 0), c(205, 0);
    for(int i = 0; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i <= n + m; i++) {
        cin >> c[i];
    } 
    for(int i = 0; i <= m; i++) {
        int x = 0;
        for(int j = 0; j < i; j++) {
            x += (b[m - j] * (n + j - i >= 0 ? a[n + j - i] : 0));
        }
        b[m - i] = (c[n + m - i] - x)/a[n];
    }
    for(int i = 0; i <= m; i++) {
        cout << b[i] << " ";
    }
    
    return 0;
}