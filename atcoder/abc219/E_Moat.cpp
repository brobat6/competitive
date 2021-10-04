#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int arr[4][4];
    forn(i, 0, 4) forn(j, 0, 4) cin >> arr[i][j];
    int dp[4][5][5];
    memset(dp, 0, sizeof(dp));
    // Set dp[0].
    int l[4], r[4];
    forn(i, 0, 4) {
        l[i] = 5;
        r[i] = -1;
    }
    forn(j, 0, 4) forn(i, 0, 4) if(arr[j][i] == 1) {
        l[j] = min(l[j], i);
        r[j] = max(r[j], i + 1);
    }
    if(l[0] >= r[0]) {
        forn(i, 0, 5) forn(j, i+1, 5) dp[0][i][j] = 1; 
    }
    else {
        forn(i, 0, 5) forn(j, i+1, 5) {
            if(i > l[0] || j < r[0]) continue;
            dp[0][i][j] = 1;
        }
    }
    forn(i, 1, 4) forn(j, 0, 5) forn(k, j+1, 5) {
        forn(a, 0, 5) forn(b, a+1, 5) {
            // Assign dp[i][a][b] based on dp[i-1][j][k].
            if(l[i] >= r[i]) {
                if(a < k && b > j) dp[i][a][b] += dp[i-1][j][k];
            }
            else {
                if(a >= k || b <= j) continue;
                if(a > l[i] || b < r[i]) continue;
                dp[i][a][b] += dp[i-1][j][k];
            }
        }
    }

    // cout << l[0] << " " << r[0] << endl;
    // forn(i, 0, 5) forn(j, i+1, 5) cout << i << " " << j << " " << dp[3][i][j] << endl;
    int ans = 0;
    forn(i, 0, 5) forn(j, 0, 5) ans += dp[3][i][j];
    cout << ans;
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