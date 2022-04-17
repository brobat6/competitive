#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    map<pair<int, int>, int> m;
    int z[4][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    for(int i = 0; i < 4; i++) {
        m[{a + z[i][0], b + z[i][1]}]++;
        m[{c + z[i][0], d + z[i][1]}]++;
        m[{a + z[i][1], b + z[i][0]}]++;
        m[{c + z[i][1], d + z[i][0]}]++;
    }
    for(auto i : m) {
        if(i.second == 2) {
            cout << "Yes";
            return;
        }
    }
    cout << "No";
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}