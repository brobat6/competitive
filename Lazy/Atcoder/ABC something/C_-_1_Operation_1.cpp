#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int x, a, d, n;
    cin >> x >> a >> d >> n;
    if(d < 0) {
        x *= -1ll;
        a *= -1ll;
        d *= -1ll;
    }
    int f = a;
    int g = a + (n - 1)*d;
    int ans = min(abs(x - f), abs(x - g));
    if(f < x && x < g) {
        int r = (x - a) % d;
        ans = min(ans, min(r, d - r));
    }
    cout << ans;

    
    return 0;
}