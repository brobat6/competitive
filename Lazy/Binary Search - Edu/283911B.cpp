#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for(int i = 0; i < q; i++) {
        int x;
        cin >> x;
        int ans = -1;
        int l = 0;
        int r = n - 1;
        while(l <= r) {
            int m = (l + r)/2;
            if(v[m] <= x) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        cout << ans + 1 << '\n';
    }
    
    return 0;
}