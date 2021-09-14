#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

int d, e;

bool check(int a, int b, int c) {
    if(a > e || b + c > d) return false;
    return true;
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c >> d >> e;
    if(check(a, b, c)||check(b, c, a)||check(c, a, b)) cout << "YES" << endl;
    else cout << "NO" << endl;
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