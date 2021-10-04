#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

int find(unsigned int n, unsigned int k) {
    return ((n & (1 << (k - 1))) >> (k - 1));
}

void solve() {
    int n;
    cin >> n;
    int m = 1<<n;
    int dp[n][m], arr[n][n];
    forn(i, 0, n) forn(j, 0, n) cin >> arr[i][j];
    forn(i, 0, n) forn(j, 0, m) dp[i][j] = 0;
    forn(i, 0, n) if(arr[0][i]) dp[0][1<<i] = 1;
    forn(i, 1, n) {
        // Assuming i men are allocated.
        forn(j, 0, m) {
            if(__builtin_popcount(j) != i) continue;
            forn(k, 0, n) {
                if(arr[i][k] && find(j, k+1)==0) {
                    dp[i][(1<<k)|j] = (dp[i][(1<<k)|j] + dp[i-1][j]) % MOD;
                }
            }
        }
    }
    // forn(i, 0, n) {forn(j, 0, m) cout << dp[i][j] << " "; cout << endl;}
    cout << dp[n-1][m-1];
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