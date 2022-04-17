#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == '1') cnt++;
        if(b[i] == '1') cnt++;
    }
    if(cnt % 2 == 1) {
        cout << -1 << endl;
        return;
    }
    cnt = 0;
    int cnt0 = 0;
    int cnt1 = 0;
    vector <int> z, o;
    o.push_back(-1E18);
    for(int i = 0; i < n - 1; i++) {
        if(a[i] == b[i]) continue;
        if(a[i] == b[i + 1] && a[i + 1] == b[i]) {
            cnt++;
        }
        if(a[i] == '0') {
            cnt0++;
        }
        else {
            cnt1++;
        }
    }
    if(a[n - 1] != b[n - 1]) {
        if(a[n - 1] == '1') cnt1++;
        else cnt0++;
    } 
    int ans = cnt1/2 + cnt0/2;
    if(cnt1 % 2) {
        if(cnt == 0) ans += 2;
        else ans += 1;
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