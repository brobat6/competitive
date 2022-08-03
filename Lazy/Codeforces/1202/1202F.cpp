#include <bits/stdc++.h>
using namespace std;
#define int long long

void check_floor(int n, set <int> &s) {
    set <int> t;
    for(int i = 1; i <= n; i++) {
        t.insert(n/i);
    }
    assert(s == t);
}

vector <int> all_floors(int n) {
    set <int> s;
    for(int i = 1; i <= sqrt(n); i++) {
        s.insert(n/i);
        s.insert(i);
    }
    vector <int> v;
    // check_floor(n, s);
    for(auto i : s) {
        v.push_back(i);
    }
    return v;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b;
    cin >> a >> b;
    int n = a + b;
    auto v = all_floors(n);
    // for(auto i : v) cerr << i << " ";
    // cerr << '\n';
    int ans = 0;
    for(auto k : v) {
        int hi = (a/k) + (b/k);
        // int x = a % k + b % k;
        // hi = min(hi, x);
        int lo;
        // find minimum X such that floor(N/X) = K.
        int l = 1;
        int r = n;
        while(l <= r) {
            int m = (l + r)/2;
            // cout << "Check " << m << " " << n/m << " " << k << '\n';
            if(n/m > k) {
                l = m + 1;
            } else {
                lo = m;
                r = m - 1;
            }
        }
        ans += max(hi - lo + 1, 0ll);
        cout << k << " " << lo << " " <<  hi << '\n';
    }
    cout << ans;
    
    return 0;
}