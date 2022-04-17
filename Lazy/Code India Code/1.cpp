#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = (a%2) + (b%2) + (c%2);
    cout << min(ans, 3 - ans) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}