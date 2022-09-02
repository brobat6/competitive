#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    bool cnt = false;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if(c == '^') cnt = true;
        }
    }
    if(cnt && min(n, m) == 1) {
        cout << "Impossible\n";
    } else {
        cout << "Possible\n";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << (cnt ? '^' : '.');
            }
            cout << '\n';
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    freopen("second_friend_input.txt", "r", stdin);
    freopen("second_friend_output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        cout << "Case #" << I << ": ";
        solve();
    }
    
    return 0;
}