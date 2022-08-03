#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = (int)1E9 + 7;
const int MAXN = 100100;

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res % MOD;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<vector<int>> v(62, vector<int>(MAXN));
    for(int i = 0; i < 62; i++) {
        // i is the length.
        int curr = 1;
        int sum = 0;
        int temp = binpow(2, i);
        for(int j = 1; j < MAXN; j++) {
            // 2^0 + 2^i + 2^...(j - 1)i.
            sum = (sum + curr) % MOD;
            curr = curr * temp % MOD;
            v[i][j] = sum;
            // cout << sum << " ";
        }
        // cout << '\n';
    }

    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int x = 0;
        int temp = 1;
        while(temp <= n) {
            temp *= 2;
            x += 1;
        }
        int curr = v[x][k];
        // cerr << curr << '\n';
        int ans = 0;
        for(int i = 0; i < x; i++) {
            if(n % 2 == 1) {
                ans = (ans + curr) % MOD;
            }
            n /= 2;
            curr = curr * 2 % MOD;
        }
        cout << ans << '\n';
    }
    
    return 0;
}