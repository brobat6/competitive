#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    cout << 1 + (n - 1)/5 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        cout << "Case #" << I << ": ";
        solve();
    }
    
    return 0;
}