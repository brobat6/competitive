#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

int e, w, X;
char choice[3] = {'R', 'P', 'S'};

void solve() {
    cin >> e >> w;
    forn(i, 0, 60) cout << choice[i%3];
    cout << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T >> X;
    forn(I, 0, T) {
        cout << "Case #" << I+1 << ": ";
        solve();
    }

    return 0;
}