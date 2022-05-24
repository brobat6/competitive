#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int k, n;
    cin >> k >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int l = 0;
    int r = 50 * (int)1E9 + 50;
    int ans = 0;
    while(l <= r) {
        int m = (l + r)/2;
        
        bool check;
        // check if M councils can be formed.
        vector <int> x(k, 0);
        vector <int> w = v;
        for(int i = 0; i < n; i++) {
            w[i] = min(w[i], m);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < k; j++) {
                if(w[i] <= 0) continue;
                if(x[j] < m) {
                    int diff = min(m - x[j], w[i]);
                    x[j] += diff;
                    w[i] -= diff;
                }
            }
        }
        check = true;
        for(int j = 0; j < k; j++) {
            if(x[j] < m) check = false;
        }

        if(check) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << ans;
    
    return 0;
}