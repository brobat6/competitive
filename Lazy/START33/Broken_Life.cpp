#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector <char> s(n), t(m);
        for(int i = 0; i < n; i++) {
            cin >> s[i];
        }
        for(int i = 0; i < m; i++) {
            cin >> t[i];
        }
        int j = 0;
        bool pos = true;
        for(int i = 0; i < n; i++) {
            if(s[i] == '?') {
                s[i] = t[j] + 1;
                if(s[i] == 'f') s[i] = 'a';
            }
            if(s[i] == t[j]) {
                j++;
                if(j == m) {
                    pos = false;
                    break;
                }
            }
        }
        if(!pos) {
            cout << -1 << endl;
        } else {
            for(auto i : s) cout << i;
            cout << endl;
        }
    }
    
    return 0;
}