#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD1 = 998244353;
const int MOD2 = (int)1E9 + 7;
int C1{0}, C2{0};
int INV1, INV2; // inverse of C1 % MOD1
int P1, P2; // c1 ^ (m - 1). 

int binpow(int a, int b, int MOD) {
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
    
    mt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());
    while(C1 == 0) { C1 = rng_64() % MOD1; }
    while(C2 == 0) { C2 = rng_64() % MOD2; }
    INV1 = binpow(C1, MOD1 - 2, MOD1);
    INV2 = binpow(C2, MOD2 - 2, MOD2);

    vector <int> cnt(26, 0);
    int m;
    {
        string s;
        cin >> s;
        m = s.length();
        for(int i = 0; i < m; i++) {
            cnt[s[i] - 'a']++;
        }
    }

    P1 = binpow(C1, m - 1, MOD1);
    P2 = binpow(C2, m - 1, MOD2);

    string s;
    cin >> s;
    int n = s.length();

    if(n < m) {
        cout << 0;
        return 0;
    }

    vector <int> curr_cnt(26, 0);
    int h1 = 0, h2 = 0;
    int p1 = 1, p2 = 1;
    for(int i = 0; i < m; i++) {
        curr_cnt[s[i] - 'a']++;
        h1 = (h1 + (int)s[i] * p1) % MOD1;
        p1 = (p1 * C1) % MOD1;
        h2 = (h2 + (int)s[i] * p2) % MOD2;
        p2 = (p2 * C2) % MOD2;
    }
    set<pair<int, int>> ans;
    for(int i = m - 1; i < n; i++) {
        if(cnt == curr_cnt) {
            ans.insert({h1, h2});
        }
        curr_cnt[s[i - m + 1] - 'a']--;
        h1 = (h1 - (int)s[i - m + 1] + MOD1) % MOD1;
        h1 = h1 * INV1 % MOD1;
        h2 = (h2 - (int)s[i - m + 1] + MOD2) % MOD2;
        h2 = h2 * INV2 % MOD2;
        if(i < n - 1) {
            curr_cnt[s[i + 1] - 'a']++;
            h1 = (h1 + (int)s[i + 1] * P1) % MOD1;
            h2 = (h2 + (int)s[i + 1] * P2) % MOD2;
        }
    }

    cout << (int)ans.size() << '\n';
    
    return 0;
}