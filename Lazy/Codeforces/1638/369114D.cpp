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
    string s; 
    cin >> s;
    --a; --b; --c; --d; 
    if(c < d) {
        for(int i = a; i < d; i++) {
            if(s[i] == '#' && s[i + 1] == '#') {
                cout << "No";
                return;
            }
        }
    } else {
        for(int i = a; i < d; i++) {
            if(s[i] == '#' && s[i + 1] == '#')
        }
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}