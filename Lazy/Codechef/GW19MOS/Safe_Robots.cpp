#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.length();
        int a, b;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'A') a = i;
            if(s[i] == 'B') b = i;
        }
        int x, y;
        cin >> x >> y;
        cout << ((b - a) % (x + y) == 0 ? "unsafe" : "safe") << '\n';
    }
    
    return 0;
}