#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int ans = 2*(n/52);
        n %= 52;
        if(n == 0) ans += 0;
        else if(n <= 26) ans += 1;
        else if(n % 2 == 0) ans += 2;
        else ans += 3;
        cout << ans << endl;
    }
    
    return 0;
}