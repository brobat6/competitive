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
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector <int> p(n);
        map<int, int> last;
        for(int i = 0; i < n; i++) {
            last[v[i]] = -1;
        }
        for(int i = 0; i < n; i++) {
            p[i] = last[v[i]];
            last[v[i]] = i;
        }
        int j = 0;
        int ans = (int)1E18;
        for(int i = 0; i < n; i++) {
            // calculate ans assuming i is final of unique subarray
            while(p[i] >= j) {
                j++;
            }
            int a = j;
            int b = n - 1 - i;
            if(a > b) swap(a, b);
            ans = min(ans, 2*a + b);
        }
        cout << ans << '\n';
    }
    
    return 0;
}