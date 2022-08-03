// Source --> https://codeforces.com/contest/1657/problem/B

#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, b, x, y;
    cin >> n >> b >> x >> y;
    int ans = 0;
    int curr = 0;
    for(int i = 1; i <= n; i++) {
        if(curr + x <= b) {
            curr += x;
        } else {
            curr -= y;
        }
        ans += curr;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}