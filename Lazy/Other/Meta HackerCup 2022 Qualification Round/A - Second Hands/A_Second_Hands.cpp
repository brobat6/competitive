#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    map <int, int> cnt;
    bool pos = true;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
        if(cnt[x] > 2) pos = false;
    }
    if(k*2 < n) pos = false;
    cout << (pos ? "YES" : "NO") << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    freopen("second_hands_input.txt", "r", stdin);
    freopen("second_hands_output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        cout << "Case #" << I << ": ";
        solve();
    }
    
    return 0;
}