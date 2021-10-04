#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    string a, b, c;
    cin >> a >> b >> c;
    string n; cin >> n;
    string ans;
    forn(i, 0, n.length()) {
        if(n[i]=='1') ans += a;
        else if(n[i]=='2') ans += b;
        else ans += c;
    }
    cout << ans;
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