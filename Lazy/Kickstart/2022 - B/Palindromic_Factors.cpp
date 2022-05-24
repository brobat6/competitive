#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector <int> f;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            f.push_back(i);
            if(i * i != n) {
                f.push_back(n/i);
            }
        }
    }
    int ans = 0;
    for(auto i : f) {
        string x = to_string(i);
        string y = x;
        reverse(y.begin(), y.end());
        if(x == y) ans++;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    for(int I = 1; I <= t; I++) {
        cout << "Case #" << I << ": ";
        solve();
    }
    
    return 0;
}