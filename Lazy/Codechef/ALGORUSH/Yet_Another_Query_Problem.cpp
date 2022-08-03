#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 200100;
const int MOD = (int)1E9 + 7;
const int INF = (int)9E18;
const char nl = '\n';

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
    
    vector <int> f(N);
    vector <int> inv(N);
    vector <int> two(N);

    two[0] = 1;
    f[0] = 1;
    inv[0] = 1;
    for(int i = 1; i < N; i++) {
        f[i] = f[i - 1] * i % MOD;
        inv[i] = binpow(f[i], MOD - 2);
        two[i] = two[i - 1] * 2 % MOD;
    }

    auto COMB = [&](int n, int r) -> int {
        if(n < r) return 0;
        return f[n] * inv[r] % MOD * inv[n - r] % MOD;
    };

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.length();
        // vector<char> cnt(26, 0);
        // for(int i = 0; i < n; i++) {
        //     cnt[s[i] - 'a']++;
        // }
        // map<int, vector <int>> v;
        // for(auto i : cnt) {
        //     if(v[i].empty()) {
        //         for(int j = 0; j <= i; j++) {
        //             v[i].push_back(COMB(i, j));
        //         }
        //         // We need prefix sum
        //         for(int j = 1; j <= i; j++) {
        //             v[i][j] += v[i][j - 1];
        //             v[i][j] %= MOD;
        //         }
        //     }
        // }
        // int q;
        // cin >> q;
        // for(int i = 0; i < q; i++) {
        //     char c;
        //     int o;
        //     cin >> c >> o;
        //     int occ = cnt[c - 'a'];
        //     if(o > occ) {
        //         cout << 0 << '\n';
        //         continue;
        //     }
        //     int ans = two[n - occ] * ((v[occ][occ] - (o == 0 ? 0 : v[occ][o - 1]) + MOD) % MOD) % MOD;
        //     cout << ans << '\n';
        // }
        int freq[26] = {};
        vector<vector<int>> v(30);
        for(auto i: s) freq[i-'a']++;
        for(int i = 0; i < 26; i++) {
            if(freq[i] == 0) {
                continue;
            }
            for(int j = 0; j <= freq[i]; j++) v[i].push_back((COMB(freq[i], j) + (v[i].empty() ? 0 : v[i].back())) % MOD);
        }
        int q; cin>>q;

        for(int i = 0; i < q; i++) {
            char C; int nn; cin>>C>>nn;
            if(nn > freq[C-'a'] || (int)s.length() < freq[C-'a']) {
                cout << 0 << nl;    
            } else {
                cout << two[(int)s.length() - freq[C-'a']]%MOD * (v[C-'a'][freq[C-'a']] - v[C-'a'][nn-1] + MOD) % MOD << nl;
            }
        }
    }
    
    return 0;
}