#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, c, q;
        cin >> n >> c >> q;
        vector <char> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        for(int i = 0; i < c; i++) {
            int l, r;
            cin >> l >> r;
            --l; --r;
            for(int j = l; j <= r; j++) {
                v.push_back(v[j]);
            }
        }
        for(int i = 0; i < q; i++) {
            int x;
            cin >> x;
            cout << v[x - 1] << '\n';
        }
    }
    
    return 0;
}