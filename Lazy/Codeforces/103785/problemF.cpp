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
        assert(k > 0);
        int done = 1;
        int curr = 1;
        int time = 0;
        while(done < n) {
            done += curr;
            time += 1;
            if(curr * 2 <= k) curr *= 2;
            else curr = k;
        }
        cout << time << '\n';
    }
    
    return 0;
}