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
        deque <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int curr = 0;
        int ans = 0;
        while(!v.empty()) {
            if(v.front() + curr < n) {
                ans++;
                curr += v.front();
                v.pop_front();
            } else {
                break;
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}