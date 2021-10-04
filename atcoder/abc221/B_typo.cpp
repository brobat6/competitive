#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    string s, t;
    cin >> s >> t;
    int ind = -1, count = 0;
    forn(i, 0, s.length()) {
        if(s[i]!=t[i]) {
            count++;
            if(count > 2) {
                cout << "No";
                return;
            }
            if(ind == -1) ind = i;
        } 
    }
    if(count == 0) {
        cout << "Yes";
        return;
    } 
    if(ind == s.length() - 1) {
        cout << "No";
        return;
    }
    if(s[ind]==t[ind+1] && t[ind]==s[ind+1]) {
        cout << "Yes";
        return;
    }
    cout << "No";
    return;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}