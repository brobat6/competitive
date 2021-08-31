#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

double exp(int x, int n) {
    // The expected number of days to eat from any one place
    // S = 1*(x/n) + 2*(1 - x/n)*(x/n) + 3*(1 - x/n)^2*(x/n) + ...
    // (1 - x/n) S = (1 - x/n)*(x/n) + 2*(1-x/n)^2*(x/n) + ...
    // (1) - (2)
    // (x/n)S = x/n + (1-x/n)(x/n) + (1-x/n)^2(x/n)
    // S = 1 + (1-x/n) + (1-x/n)^2 + ...
    // S = n/x
    // LOL.
}

void solve() {
    int n;
    cin >> n;
    double dp[n+1][n+1][n+1];
    int arr[n];
    forn(i, 0, n) cin >> arr[i];
    map<int, int> m;
    m[1] = 0; m[2] = 0; m[3] = 0;
    forn(i, 0, n) m[arr[i]]++;
    dp[0][0][0] = 0;
    forn(i, 1, n+1) dp[0][0][i] = n/(double)(i) + dp[0][0][i-1];
    forn(i, 1, n+1) {
        forn(j, 0, n-i+1) {
            dp[0][i][j] = n/(double)(i+j) + i/(double)(i+j) * dp[0][i-1][j+1];
            if(j!=0) dp[0][i][j] += j/(double)(i+j) * dp[0][i][j-1]; 
        }
    }
    forn(i, 1, m[3] + 1) {
        forn(j, 0, n - i + 1) {
            forn(k, 0, n - i - j + 1) {
                dp[i][j][k] = n/(double)(i+j+k) + i/(double)(i+j+k) * dp[i-1][j+1][k];
                if(j!=0) dp[i][j][k] += j/(double)(i+j+k) * dp[i][j-1][k+1];
                if(k!=0) dp[i][j][k] += k/(double)(i+j+k) * dp[i][j][k-1];
            }
        }
    }
    cout << setprecision(15) << dp[m[3]][m[2]][m[1]];
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