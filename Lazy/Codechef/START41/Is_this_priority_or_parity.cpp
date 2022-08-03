#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        if(k == 1) cout << (n % 2 ? "ODD" : "EVEN");
        else if(k == 2) cout << "ODD";
        else cout << "EVEN";
        cout << '\n';
    }
    
    return 0;
}