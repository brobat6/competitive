#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000009;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res % MOD;
}

vector <int> A, B, AB;

// (B^CK - A^CK)/(B^K - A^K)

void solve() {
    int n, k, a, b;
    cin >> n >> a >> b >> k;
    A.resize(k);
    B.resize(k);
    A[k - 1] = 1;
    B[0] = 1;
    for(int i = 1; i < k; i++) {
        // A[i] = (A[i - 1] * ) 
        B[i] = (B[i - 1] * b) % MOD;
        A[k - i - 1] = (A[k - i] * a) % MOD;
    }
    string s;
    cin >> s;
    int ans1 = 0;
    int ans2 = 0;
    for(int i = 0; i < k; i++) {
        ans1 = (ans1 + (s[i] == '+' ? 1 : (-1 + MOD)) * A[i] % MOD * B[i] % MOD);
    }
    int c = (n + 1)/k;
    int lol = binpow(b, c*k) - binpow(a, c*k) + MOD;
    lol %= MOD;
    int lmao = binpow(b, k) - binpow(a, k) + MOD;
    lmao %= MOD;
    lmao = binpow(lmao, MOD - 2);
    while(ans1 < 0) ans1 += MOD;
    while(lol < 0) lol += MOD;
    while(lmao < 0) lmao += MOD;
    cout << ans1 * lol % MOD * lmao % MOD;
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}