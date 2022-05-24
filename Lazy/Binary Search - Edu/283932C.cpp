#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, x, y;
    cin >> n >> x >> y;
    if(x > y) swap(x, y);
    n -= 1;
    int l = 0;
    int r = (int)2E9;
    int ans = 0;
    while(l <= r) {
        int m = (l + r)/2;

        bool check = (m/y + m/x) >= n;

        if(check) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << ans + x;
    
    return 0;
}