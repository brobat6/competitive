#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, l, r;
    cin >> n >> l >> r;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int ans = min(l, r) * n;
    ans = min(ans, accumulate(v.begin(), v.end(), 0ll));
    vector <int> p(n);
    p[0] = min(v[0], l);
    for(int i = 1; i < n; i++) {
        p[i] = min(p[i - 1] + v[i], l*(i + 1));
    }
    vector <int> q(n);
    q[n - 1] = min(v[n - 1], r);
    for(int i = n - 2; i >= 0; i--) {
        q[i] = min(q[i + 1] + v[i], r*(n - i));
    }
    for(int i = 0; i < n - 1; i++) {
        ans = min(ans, p[i] + q[i + 1]);
    }
    ans = min(ans, p[n - 1]);
    ans = min(ans, q[0]);
    cout << ans;
    
    return 0;
}