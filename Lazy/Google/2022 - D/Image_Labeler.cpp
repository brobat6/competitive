#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    long double ans = 0;
    for(int i = 0; i < m - 1; i++) {
        ans += v.back();
        v.pop_back();
    }
    int x = v.size();
    if(x % 2) {
        ans += v[x/2];
    } else {
        ans += (v[x/2] + v[x/2 - 1])*1.0/2;
    }
    cout << setprecision(15) << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        cout << "Case #" << I << ": ";
        solve();
    }
    
    return 0;
}