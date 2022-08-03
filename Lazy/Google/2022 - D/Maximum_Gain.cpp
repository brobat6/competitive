#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m, k;
    cin >> n;
    vector <int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    vector <int> b(m);
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    cin >> k;
    vector <int> f(k + 1, 0), s(k + 1, 0);
    int t1 = 0;
    for(int i = 0; i <= min(n, k); i++) {
        if(i > 0) t1 += a[i - 1];
        int t2 = 0;
        for(int j = 0; j <= min(n, k) - i; j++) {
            if(j > 0) t2 += a[n - j];
            f[i + j] = max(f[i + j], t1 + t2);
        }
    }
    t1 = 0;
    for(int i = 0; i <= min(m, k); i++) {
        if(i > 0) t1 += b[i - 1];
        int t2 = 0;
        for(int j = 0; j <= min(m, k) - i; j++) {
            if(j > 0) t2 += b[m - j];
            s[i + j] = max(s[i + j], t1 + t2);
        }
    }
    // for(auto i : f) cout << i << " "; cout << '\n';
    // for(auto i : s) cout << i << " "; cout << '\n';
    int ans = 0;
    for(int i = 0; i <= k; i++) {
        ans = max(ans, f[i] + s[k - i]);
    }
    cout << ans << '\n';
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