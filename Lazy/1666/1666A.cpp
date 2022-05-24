#include <bits/stdc++.h>
using namespace std;
#define int long long

const int P = 31;
const int MOD = (int)1E9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    int n = s.length();
    map<pair<int, int>, char> h;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int u = 0, l = 0, r = 0, d = 0;
        int hx = 0;
        int hy = 0;
        int p = 1;
        for(int j = i; j < n; j++) {
            s[j] == 'U' ? u++, hy += p: (s[j] == 'D' ? d++, hy -= p : (s[j] == 'R' ? r++, hx += p : l++, hx -= p));
            hx = (hx + MOD) % MOD; hy = (hy + MOD) % MOD;
        }
    }
    cout << ans;
    
    return 0;
}