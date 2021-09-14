#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    int n, t;
    cin >> n;
    int o = 0, e = 0;
    forn(i, 0, n) {
        cin >> t;
        if(t%2) o++;
        else e++;
    }
    cout << (min(n/2, o) + min(e, (n+1)/2)) << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}