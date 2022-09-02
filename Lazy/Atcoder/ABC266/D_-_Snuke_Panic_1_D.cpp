#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int v[N][5];
long long dp[N][5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(v, 0, sizeof(v));
    for(int j = 0; j < 5; j++) {
        dp[0][j] = -(int)1E18;
    }
    dp[0][0] = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, t, a;
        cin >> t >> x >> a;
        v[t][x] = a;
    }
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < 5; j++) {
            dp[i][j] = dp[i - 1][j];
            if(j > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            if(j < 4) dp[i][j] = max(dp[i][j], dp[i - 1][j + 1]);
            dp[i][j] += v[i][j];
        }
    }
    long long ans = 0;
    for(int j = 0; j < 5; j++) {
        ans = max(ans, dp[N - 1][j]);
    }
    cout << ans;
    
    return 0;
}