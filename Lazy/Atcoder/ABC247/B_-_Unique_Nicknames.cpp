#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<string> s(n), t(n);
    bool pos = true;
    for(int i = 0; i < n; i++) {
        cin >> s[i] >> t[i];
    }
    for(int i = 0; i < n; i++) {
        int x = 0;
        int y = 0;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(s[i] == s[j] || s[i] == t[j]) x = 1;
            if(t[i] == s[j] || t[i] == t[j]) y = 1;
        }
        if(x && y) pos = false;
    }
    cout << (pos ? "Yes" : "No");
    
    return 0;
}