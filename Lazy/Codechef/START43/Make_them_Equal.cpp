#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        for(int i = 0; i <= 30; i++) {
            if(a == b && b == c) break;
            int d = (a>>i) & 1;
            int e = (b>>i) & 1;
            int f = (c>>i) & 1;
            int x = (d<<2) + (e<<1) + f;
            switch(x) {
                case 1: c += (1<<i); break;
                case 2: b += (1<<i); break;
                case 4: a += (1<<i); break;
                case 3: a += (1<<i); break;
                case 5: b += (1<<i); break;
                case 6: c += (1<<i); break;
                default: a += (1<<i); break;
            }
        }
        cout << (a == b && b == c ? "YES" : "NO") << '\n';
    }
    
    return 0;
}