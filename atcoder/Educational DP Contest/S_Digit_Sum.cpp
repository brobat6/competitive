#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

/*
THOUGHTS - 
dp[len(K)][Digit(0 - 9)][remainder when divided by D] - The answer for this
dp[i][j][(k+j)%d] = sum(dp[i-1][j][k]) for all j. Anyway to store the sums??
sum[i][k] ---> The sum of dp[i][j][k] for all j in 0 to 9.
*/

void solve() { 
    string s; cin >> s;
    int n = s.length();
    int d; cin >> d;
    int arr[n], dp[n][10][d], sum[n][d];
    forn(i, 0, n) arr[i] = s[i] - '0';
    memset(dp, 0, sizeof(dp));
    memset(sum, 0, sizeof(sum));
    forn(i, 0, 10) {
        dp[0][i][i%d]++;
        sum[0][i%d]++;
    }
    forn(i, 1, n) forn(j, 0, 10) forn(k, 0, d) {
        dp[i][j][(k+j)%d] = sum[i-1][k];
        sum[i][(k+j)%d] = (sum[i][(k+j)%d] + dp[i][j][(k+j)%d]) % MOD;
    }
    int ans = 0;
    int done = 0;
    forn(i, 0, n) {
        forn(j, 0, arr[i]) {
            ans = (ans + dp[n - i - 1][j][(0 - done + d) % d]) % MOD;
        }
        done = (done + arr[i]) % d;
    }
    // Check for 0 and current number
    int temp = 0;
    forn(i, 0, n) temp = (temp + arr[i]) % d;
    if(temp != 0) ans = (ans - 1 + MOD) % MOD;
    cout << ans << endl;
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