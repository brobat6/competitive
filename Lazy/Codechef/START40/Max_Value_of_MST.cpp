#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector <int> v(m);
        for(int i = 0; i < m; i++) {
            cin >> v[i];
        }
        if(m == 0) {
            cout << 0 << '\n';
            continue;
        }
        sort(v.begin(), v.end());
        vector <bool> d(m, false);
        int gap = 1;
        int done = 1;
        d[0] = true;
        int cov = 1;
        for(int i = 1; i < m; i++) {
            if(done == n - 1) break;
            // cout << cov << " " << gap << '\n';
            if(cov == gap) {
                d[i] = true;
                done++;
                gap++;
                cov = 0;
            }
            cov++;
        }
        int i = m - 1;
        while(done < n - 1) {
            if(d[i] == false) {
                done++;
                d[i] = true;
            } 
            i--;
        }
        int ans = 0;
        // for(int i = 0; i < m; i++) {
        //     cerr << d[i] << " ";
        // }
        // cerr << '\n';
        for(int i = 0; i < m; i++) {
            if(d[i]) ans += v[i];
        }
        cout << ans << '\n';
    }
    
    return 0;
}