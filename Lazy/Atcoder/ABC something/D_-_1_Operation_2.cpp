#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector <int> v(n);
    vector <int> p(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    p[0] = v[0];
    for(int i = 1; i < n; i++) {
        p[i] = p[i - 1] + v[i];
    }
    for(int i = 0; i < q; i++) {
        int x;
        cin >> x;
        int c = lower_bound(v.begin(), v.end(), x) - v.begin();
        if(c == 0) {
            cout << p[n - 1] - n*x << '\n';
        } else {
            cout << (c*x - p[c - 1]) + (p[n - 1] - p[c - 1] - (n - c)*x) << '\n';
        }
    }
    
    return 0;
}