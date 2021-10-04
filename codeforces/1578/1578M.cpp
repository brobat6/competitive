#include <bits/stdc++.h>
using namespace std;

#define int long long
// #define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

vector <vector<double>> ans(101);

void pre() {
    forn(i, 1, 101) {
        ans[i] = {0, 0, 0, 0, 0};
    }
    forn(i, 1, 2) {
        ans[i][0] = 1.0;
    }
    forn(i, 2, 4) ans[i][1] = 1.0;
    forn(i, 4, 8) ans[i][2] = 1.0;
    forn(i, 8, 16) ans[i][3] = 1.0;
    forn(i, 16, 32) ans[i][4] = 1.0;
}

void solve() {
    vector <int> v(5);
    forn(i, 0, 5) cin >> v[i];
    forn(i, 0, 5) cout << ans[v[0]][i] << " ";
    cout << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    pre();
    while(T--) solve();

    return 0;
}