#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        v[i] /= (i + 1);
    }
    int ans = 2 * abs(v[1] - v[0]);
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if((i + 1) * (j + 1) > ans) break;
            ans = min(ans, (i + 1) * (j + 1) * abs(v[j] - v[i]));
        }
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n - 1; i++) {
        if(v[i] == v[i + 1]) {
            ans = 0;
            break;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}