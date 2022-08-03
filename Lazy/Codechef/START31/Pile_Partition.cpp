#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    bool pos = false;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x = x % (n*n - n);
        if(x > n - 1 || x == 0) {
            pos = true;
        } 
    }
    cout << (pos ? "Alice" : "Bob") << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}