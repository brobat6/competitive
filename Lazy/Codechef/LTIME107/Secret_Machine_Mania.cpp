#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, c;
        cin >> n >> c;
        map<int, int> f;
        int i = 2;
        while(n > 1) {
            if(i * i > n) break;
            if(n % i == 0) {
                n /= i;
                f[i]++;
            } else {
                i++;
            }
        }
        if(n > 1) {
            f[n]++;
            n = 1;
        }
        int ans = 1;
        for(auto i : f) {
            int x = i.second;
            x %= c;
            x = min(x, c - x);
            for(int j = 0; j < x; j++) {
                ans *= i.first;
            }
        }
        cout << ans << '\n';
        // for(auto i : f) cout << i.first << " " << i.second << '\n';
        // cout << '\n';
    }
    
    return 0;
}