#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        bool pos = false;
        if(a == b) {
            cout << "YES" << '\n';
            continue;
        }
        string c, d;
        for(int i = 0; i < n; i++) {
            c += (i % 2 ? '1' : '0');
            d += (i % 2 ? '0' : '1');
        }
        int x = 0;
        int y = 0;
        for(int i = 0; i < n; i++) {
            x += a[i] == '1';
            y += b[i] == '1';
        }
        if(x == 0) {
            cout << "NO" << '\n';
            continue;
        }
        if(c == b || d == b) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
    }
    
    return 0;
}