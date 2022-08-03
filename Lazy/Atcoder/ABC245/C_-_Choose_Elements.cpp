#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector <int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<vector<bool>> dp(n, vector<bool>(2, false));
    dp[0][0] = true;
    dp[0][1] = true;
    for(int i = 1; i < n; i++) {
        if(dp[i - 1][0]) {
            if(abs(a[i] - a[i - 1]) <= k) dp[i][0] = true;
            if(abs(b[i] - a[i - 1]) <= k) dp[i][1] = true;
        }
        if(dp[i - 1][1]) {
            if(abs(a[i] - b[i - 1]) <= k) dp[i][0] = true;
            if(abs(b[i] - b[i - 1]) <= k) dp[i][1] = true;
        }
    }
    cout << (dp[n - 1][0]||dp[n - 1][1] ? "Yes" : "No");
    
    return 0;
}