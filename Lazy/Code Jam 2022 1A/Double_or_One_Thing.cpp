#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    string s;
    cin >> s;
    string ans;
    int n = s.length();
    for(int i = 0; i < n; i++) {
        ans += s[i];
        for(int j = i + 1; j < n; j++) {
            if(s[j] > s[i]) {
                ans += s[i];
                break;
            }
            if(s[j] < s[i]) {
                break;
            }
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    
    return 0;
}