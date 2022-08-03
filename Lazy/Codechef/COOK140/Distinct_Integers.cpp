#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int range = (*max_element(v.begin(), v.end())) - (*min_element(v.begin(), v.end()));
        int ans = 0;
        for(int i = 2; i <= range; i++) {
            
        }
    }
    
    return 0;
}