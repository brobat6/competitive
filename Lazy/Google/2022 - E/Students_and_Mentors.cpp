#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector <pair<int, int>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    vector <int> ans(n, -1);
    sort(v.begin(), v.end());
    vector <int> w(n);
    for(int i = 0; i < n; i++) w[i] = v[i].first;
    for(int i = 0; i < n; i++) {
        int x = upper_bound(w.begin(), w.end(), v[i].first * 2) - w.begin();
        if(x == 0) continue;
        --x;
        if(v[x].second == v[i].second) {
            if(x == 0) continue;
            --x;
            ans[v[i].second] = v[x].first;
        } else {
            ans[v[i].second] = v[x].first;
        }
    }
    for(auto i : ans) cout << i << ' ';
    cout << '\n';
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