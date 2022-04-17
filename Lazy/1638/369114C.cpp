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
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int a = 0, b = 0, sa = 0, sb = 0;
    forn(i, 0, n) {
        sa += v[i];
        sb += v[i];
        if(i % 2) {
            if(sa >= 0) {
                a += (sa + 1);
                sa = -1;
            } 
            if(sb <= 0) {
                b += (1 - sb);
                sb = 1;
            }
        } else {
            if(sa <= 0) {
                a += (1 - sa);
                sa = 1;
            } 
            if(sb >= 0) {
                b += (sb + 1);
                sb = -1;
            }
        }
    }
    cout << min(a, b) << endl;
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