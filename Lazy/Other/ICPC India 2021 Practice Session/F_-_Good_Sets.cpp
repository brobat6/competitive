#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = (int)1E9 + 7;
const int MAXN = 750005;
ll dp[MAXN];
int arr[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        memset(dp, 0ll, sizeof(dp));
        ll ans = 0;
        for(int i = n - 1; i >= 0; i--) {
            int x = arr[i];
            dp[x]++;
            for(int j = 2*x; j <= arr[n - 1]; j += x) {
                dp[x] += dp[j];
            }
            dp[x] %= MOD;
            ans = (ans + dp[x]) % MOD;
        }
        cout << ans << '\n';
    }
    
    return 0;
}