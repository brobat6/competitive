#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        int arr[n];
        for(int i = 0; i < n; i++) {
            arr[i] = 1;
        }
        for(int i = 0; i < q; i++) {
            int a, b, c, d;
            cin >> a >> b >> c;
            --b; --c;
            if(a == 1) {
                cin >> d;
                for(int i = b; i <= c; i++) {
                    arr[i] *= d;
                }
            } else {
                int ans = 1;
                for(int i = b; i <= c; i++) {
                    ans *= arr[i];
                }
                int x = sqrt(ans);
                cout << (x * x == ans ? "YES" : "NO") << endl;
            }
        }
    }
    
    return 0;
}