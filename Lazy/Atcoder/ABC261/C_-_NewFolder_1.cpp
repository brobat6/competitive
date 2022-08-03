#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    map<string, int> m;
    for(int i = 0; i < n; i++) {
        string t;
        cin >> t;
        if(m.find(t) == m.end()) {
            cout << t << '\n';
        } else {
            cout << t << "(" << m[t] << ")" << '\n';
        }
        m[t]++;
    }
    
    return 0;
}