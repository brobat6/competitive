#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n, d;
    cin >> n >> d;
    vector <int> v(n);
    forn(i, 0, n) cin >> v[i];
    reverse(v.begin(), v.end());
    int ans = d;
    forn(i, 0, n) ans = (ans/v[i])*v[i];
    cout << ans << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    forn(I, 1, T + 1) {
        cout << "Case #" << I << ": ";
        solve();
    }

    return 0;
}