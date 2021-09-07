#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int l, q, t1, t2;
    cin >> l >> q;
    set<int> s;
    s.insert(0); s.insert(l);
    forn(i, 0, q) {
        cin >> t1 >> t2;
        if(t1==1) s.insert(t2);
        else {
            auto it = s.lower_bound(t2);
            cout << (*it) - *(--it) << endl;
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
    while(T--) solve();

    return 0;
}