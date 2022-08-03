#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int MOD = 998244353;

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
    
    int n, l;
    cin >> n >> l;
    int pw[27];
    for(int i = 0; i <= 26; i++) {
        pw[i] = binpow(i, l);
    }
    vector<string> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int ans = 0;
    for(int i = 1; i < (1<<n); i++) {
        int x = __builtin_popcount(i);
        vector <int> cnt(26, 0);
        for(int j = 0; j < n; j++) {
            if((i >> j) & 1) {
                for(auto k : s[j]) cnt[k - 'a']++;
            }
        }
        int tot = 0;
        for(int j = 0; j < 26; j++) {
            if(cnt[j] == x) tot++;
        }
        if(x % 2 == 1) {
            ans = (ans + pw[tot]) % MOD;
        } else {
            ans = (ans + MOD - pw[tot]) % MOD;
        }
    }
    cout << ans;
    
    return 0;
}