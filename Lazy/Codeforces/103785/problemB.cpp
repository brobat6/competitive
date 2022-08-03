#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    assert(1 <= t <= 10);
    while(t--) {
        int n;
        cin >> n;
        assert(1 <= n <= 1000000);
        int ans = 0;
        int x = 0;
        for(int i = 1; i <= n; i++) {
            if(x + i <= n) {
                x += i;
                ans += 1;
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}