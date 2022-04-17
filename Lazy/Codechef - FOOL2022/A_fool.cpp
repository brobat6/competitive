#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    vector <int> b;
    int i = 0;
    while(n > 0 || (i < 5)) {
        b.push_back(n % 2);
        n /= 2;
        i++;
    }
    for(int j = 0; j < 5; j++) {
        b[j] = !b[j];
    }
    int ans = 0;
    int pw = 0;
    for(auto j : b) {
        ans += (j << pw);
        pw++;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}