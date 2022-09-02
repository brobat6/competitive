#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(n % i != 0) continue;
        bool pos = true;
        string x;
        for(int j = 0; j < i; j++) x += s[j];
        for(int j = 0; j < n; j += i) {
            string t; string u;
            for(int k = 0; k < i; k++) {
                t += s[j + k];
                u += s[j + k];
            }
            if(x != t) {
                pos = false;
                break;
            }
            reverse(u.begin(), u.end());
            if(t != u) {
                pos = false;
                break;
            }
        }
        if(pos) {
            ans = i;
            break;
        }
    }
    string t;
    for(int i = 0; i < ans; i++) t += s[i];
    cout << t << '\n';
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