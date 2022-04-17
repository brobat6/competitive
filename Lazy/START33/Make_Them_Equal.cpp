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
        int n;
        cin >> n;
        int o = 0, e = 0;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if(x % 2) o++;
            else e++;
        }
        if(o % 2) cout << e;
        else cout << min(o/2, e);
        cout << endl;
    }
    
    return 0;
}