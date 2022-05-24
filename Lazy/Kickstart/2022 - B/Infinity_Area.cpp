#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int r, a, b;
    cin >> r >> a >> b;
    vector <int> v;
    v.push_back(r);
    for(int i = 1; ; i++) {
        if(v[i - 1] == 0) break;
        if(i % 2) v.push_back(v[i - 1] * a);
        else v.push_back(v[i - 1] / b);
    }
    long double ans = 0;
    for(auto i : v) {
        ans += (M_PI * i * i);
    }
    cout << setprecision(15) << ans << '\n';
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