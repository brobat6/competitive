#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    map<pair<int, int>, bool> m;
    vector <pair<int, int>> v(n);
    forn(i, 0, n) {
        cin >> v[i].first >> v[i].second;
        m[v[i]] = true;
    }
    int ans = 0;
    forn(i, 0, n) {
        forn(j, i+1, n) {
            auto a = v[i];
            auto b = v[j];
            if(a.first==b.first||a.second==b.second) continue;
            if(m[{a.first, b.second}] && m[{b.first, a.second}]) ans++;
        }
    }
    cout << ans/2 << endl;
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