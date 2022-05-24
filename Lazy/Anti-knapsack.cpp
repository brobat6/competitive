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
        int done = 0;
        for(int i = 1; i <= n; i++) {
            if(done + i < k) {
                cout << i << " ";
                done += i;
            } else {
                cout << 20000;
                break;
            }
        }
        cout << '\n';
    }
    
    return 0;
}