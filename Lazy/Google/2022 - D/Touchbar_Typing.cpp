#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int m;
    cin >> m;
    vector <int> k(m);
    for(int i = 0; i < m; i++) {
        cin >> k[i];
    }
    vector <int> t(m, 0);
    for(int x = n - 2; x >= 0; x--) {
        priority_queue<pair<int, int>> pq;
        vector <int> nt(m, -1);
        for(int i = 0; i < m; i++) {
            if(v[x + 1] == k[i]) {
                nt[i] = t[i];
                pq.push({-nt[i], i});
            }
        }
        while(!pq.empty()) {
            int tm = -pq.top().first;
            int curr = pq.top().second;
            pq.pop();
            if(tm != nt[curr]) {
                continue;
            }
            for(auto y : {-1, 1}) {
                int nx = curr + y;
                if(nx < 0 || nx >= m) continue;
                if(nt[nx] == -1 || nt[nx] > tm + 1) {
                    nt[nx] = tm + 1;
                    pq.push({-nt[nx], nx});
                }
            }
        }
        t = nt;
    }
    int ans = (int)1E18;
    for(int i = 0; i < m; i++) {
        if(k[i] == v[0]) {
            ans = min(ans, t[i]);
        }
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