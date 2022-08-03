#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int x = 0;
        for(int i = 0; i < 2*n; i++) {
            x += (s[i] == '(' ? 1 : -1);
            cout << x << " ";
        }
        cout << '\n';
    }
    
    return 0;
}