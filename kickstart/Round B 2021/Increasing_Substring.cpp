#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    int n;
    cin >> n;
    char arr[n];
    int dp[n];
    forn(i, 0, n) cin >> arr[i];
    dp[0] = 1;
    forn(i, 1, n) {
        if(arr[i]>arr[i-1]) dp[i] = dp[i-1] + 1;
        else dp[i] = 1;
    }
    forn(i, 0, n) cout << dp[i] << " ";
    cout << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    forn(i, 1, T+1) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}