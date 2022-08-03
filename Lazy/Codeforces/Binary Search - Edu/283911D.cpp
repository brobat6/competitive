#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        int l = 0;
        int r = n - 1;
        int a = n;
        while(l <= r) {
            int m = (l + r)/2;
            if(v[m] >= x) {
                a = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        l = 0;
        r = n - 1;
        int b = -1;
        while(l <= r) {
            int m = (l + r)/2;
            if(v[m] <= y) {
                b = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        cout << b - a + 1 << " ";
    }
    
    return 0;
}