#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

int pw[55];

void pre() {
    pw[0] = 1;
    forn(i, 1, 55) pw[i] = pw[i-1]*2;
}

void solve() {
    int h, p;
    cin >> h >> p;  
    int ans = 0;
    int change;
    forn(i, 0, h) {
        if(p > pw[i]) {
            ans += 1;
        }
        else {
            change = i;
            break;
        }
    }
    int sum = 0;
    forn(i, change, h) {
        sum += pw[i];
    }
    ans += ceil(sum/(p*1.0));
    cout << ans << endl;
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