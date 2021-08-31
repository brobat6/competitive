#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

bitset<100100> dp;

void solve() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    forn(i, 0, n) cin >> arr[i];
    forn(i, 0, k+1) dp[i] = 0;
    forn(i, 1, k+1) {
        forn(j, 0, n) {
            // dp[i] = dp[i]|!dp[max(0ll, i - arr[j])];
            if(i >= arr[j]) dp[i] = dp[i]|(!dp[i - arr[j]]);
        }
    }
    if(dp[k]) cout << "First";
    else cout << "Second";
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