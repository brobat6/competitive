#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, k, x;
    cin >> n >> k >> x;
    vector <int> v(n);
    int full = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        full += v[i]/x;
    }
    if(k <= full) {
        cout << accumulate(v.begin(), v.end(), 0ll) - k*x;
    } else {
        for(int i = 0; i < n; i++) {
            v[i] %= x;
        }
        k -= full;
        sort(v.begin(), v.end(), greater<int>());
        for(int i = 0; i < k; i++) {
            if(i == n) break;
            v[i] = 0;
        }
        cout << accumulate(v.begin(), v.end(), 0ll);
    }
    
    return 0;
}