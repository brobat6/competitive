#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    int n, m, t;
    cin >> n >> m;
    multiset <int> s;
    forn(i, 0, n) {
        cin >> t;
        s.insert(t);
    }
    forn(i, 0, m) {
        cin >> t;
        if(s.empty()) {
            cout << -1 << endl;
            continue;
        }
        auto x = s.upper_bound(t); 
        if(x!=s.begin()) --x;
        if(*x > t) cout << -1 << endl;
        else {
            cout << *x << endl;
            s.erase(s.lower_bound(*x));
        }
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}