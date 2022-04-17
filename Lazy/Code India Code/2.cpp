#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    int cnt = 0;
    while(n) {
        if(n % 2 == 0) break;
        cnt++;
        n /= 2;
    }
    cout << (1ll << cnt) << endl;
}

int32_t main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}