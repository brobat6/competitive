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
        vector <int> a(n), b(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        map<int, int> m;
        for(int i = 0; i < n; i++) {
            m[a[i] ^ b[i]]++;
        }
        int ans = 0;
        for(auto i : m) {
            ans += (i.second)*(i.second - 1)/2;
        }
        cout << ans << '\n';
    }
    
    return 0;
}