#include <bits/stdc++.h>
using namespace std;
#define int long long

#define ff(a) for(int a = 1; a < 7; a++)

const int MOD = (int)1E9 + 7;
const int MAXN = 100100;

int fact[MAXN];
int inv[MAXN];

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res % MOD;
}

void pre() {
    fact[0] = 1;
    inv[0] = 1;
    for(int i = 1; i < MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = binpow(fact[i], MOD - 2);
    }
}

int comb(int n, int r) {
    if(r > n) return 0;
    return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}

bool good(vector <int> &v) {
    int n = v.size();
    for(int i = 0; i < (1<<n); i++) {
        int x = 0;
        for(int j = 0; j < n; j++) {
            if((i >> j) & 1) x += v[j];
        }
        int y = __builtin_popcount(i);
        if(y % 7 == 0 && x % 7 != 0) {
            // cout << x << " " << y << '\n';
            return false;
        }
        if(y % 7 != 0 && x % 7 == 0) {
            // cout << x << " " << y << '\n';
            return false;
        }
    }
    return true;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector <int> ugh = {1, 1, 2};
    good(ugh);
    
    int T;
    cin >> T;
    pre();
    while(T--) {
        int n, q;
        cin >> n >> q;
        vector <int> v(7, 0);
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v[x % 7]++;
        }
        // k >= 6 --> ans is easy. Find for k = 1 to k = 5.
        vector <int> ans(6, 0);
        vector <int> t;
        map <int, int> m;
        for(int a = 1; a < 7; a++) {
            t.push_back(a);
            if(!good(t)) {
                t.pop_back();
                continue;
            }
            m[a]++;
            int j = 0;
            j++;
            int lol = 1;
            for(auto i : m) {
                lol = (lol * comb(v[i.first], i.second)) % MOD;
            }
            ans[1] = (ans[1] + lol) % MOD;
            for(int b = a; b < 7; b++) {
                t.push_back(b);
                
                if(!good(t)) {
                    t.pop_back();
                    continue;
                }
                m[b]++;
                // cout << a << " " << b << " " << m[a] << " " << m[b] << '\n';
                j++;
                int lol = 1;
                for(auto i : m) {
                    lol = (lol * comb(v[i.first], i.second)) % MOD;
                }
                // cout << a << " " << b << " " << lol << '\n';
                ans[2] = (ans[2] + lol) % MOD;
                for(int c = b; c < 7; c++) {
                    t.push_back(c);
                    
                    // cout << a << " " << b << " " << c << '\n';
                    // for(auto i : t) cout << i << " ";
                    // cout << '\n';
                    if(!good(t)) {
                        t.pop_back();
                        continue;
                    }
                    m[c]++;
                    // cout << a << " " << b << " " << c << '\n';
                    j++;
                    int lol = 1;
                    for(auto i : m) {
                        lol = (lol * comb(v[i.first], i.second)) % MOD;
                    }
                    ans[3] = (ans[3] + lol) % MOD;
                    for(int d = c; d < 7; d++) {
                        t.push_back(d);
                        
                        if(!good(t)) {
                            t.pop_back();
                            continue;
                        }
                        m[d]++;
                        j++;
                        int lol = 1;
                        for(auto i : m) {
                            lol = (lol * comb(v[i.first], i.second)) % MOD;
                        }
                        ans[4] = (ans[4] + lol) % MOD;
                        for(int e = d; e < 7; e++) {
                            t.push_back(e);
                            
                            if(!good(t)) {
                                t.pop_back();
                                continue;
                            }
                            m[e]++;
                            j++;
                            int lol = 1;
                            for(auto i : m) {
                                lol = (lol * comb(v[i.first], i.second)) % MOD;
                            }
                            ans[5] = (ans[5] + lol) % MOD;
                            t.pop_back();
                            m[e]--;
                        }
                        t.pop_back();
                        m[d]--;
                    }
                    t.pop_back();
                    m[c]--;
                }
                t.pop_back();
                m[b]--;
            }
            t.pop_back();
            m[a]--;
        }
        // cout << 'f';
        // for(int i = 1; i <= 5; i++) {
        //     cout << ans[i] << " ";
        // }
        // cout << '\n';
        for(int i = 0; i < q; i++) {
            int k;
            cin >> k;
            if(k < 6) cout << ans[k] << '\n';
            else {
                int x = 0;
                for(int i = 1; i < 7; i++) {
                    x = (x + comb(v[i], k)) % MOD;
                }
                cout << x << '\n';
            }
        }
    }
    
    return 0;
}