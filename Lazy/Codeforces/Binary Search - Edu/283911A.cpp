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
    sort(v.begin(), v.end());
    for(int i = 0; i < q; i++) {
        int x;
        cin >> x;
        int l = 0;
        int r = n - 1;
        bool found = false;
        while(l <= r) {
            int m = (l + r)/2;
            if(v[m] == x) {
                found = true;
                break;
            } else if(v[m] < x) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        cout << (found ? "YES" : "NO") << '\n';
    }
    
    return 0;
}