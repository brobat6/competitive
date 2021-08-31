#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 1010
#define MOD 1000000007

int n;
long double arr[MAXN];
long double dp[MAXN][MAXN][2];

// 0 --> Bob
// 1 --> Alice

void solve() {
    cin >> n;
    forn(i, 0, n) cin >> arr[i];
    forn(i, 0, n) {
        dp[i][i][1] = arr[i];
        dp[i][i][0] = 0;
    }
    // k - the difference. 1 to n - 1.
    // i ---> 0 to n - k - 1
    forn(k, 1, n) {
        forn(i, 0, n - k) {
            int j = i + k;
            dp[i][j][1] = (0.5) * (arr[i] + arr[j] + dp[i+1][j][0] + dp[i][j-1][0]);
            dp[i][j][0] = (0.5) * (dp[i+1][j][1] + dp[i][j-1][1]);
        }
    }
    cout << dp[0][n-1][1] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t; cin >> t; while(t--)
{
    // Code goes here
    solve();
}
    return 0;
}