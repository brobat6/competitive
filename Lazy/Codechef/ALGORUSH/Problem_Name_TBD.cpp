#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = (int)1E7 + 19;
// const int MOD = 5;

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res % MOD;
}

vector <int> f(MOD*3);

int fact(int x) {
    if(x >= MOD*3) return 0;
    return f[x];
}

int comb(int n, int r) {

    if(n < r) return 0;
    // if(r < MOD || (n - r) < MOD) return 0;

    if(r > n/2) r = n - r;

    if(r > MOD * 20) return 0;

     
    int ans = 1;
    for(int i = 0; i < r; i++) {
        ans = ans * (n - i) % MOD;
        ans = ans * binpow(i + 1, MOD - 2) % MOD;
    }

    return ans;

    // return fact(n) * binpow(fact(r), MOD - 2) % MOD * binpow(fact(n - r), MOD - 2) % MOD;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    f[0] = 1;
    for(int i = 1; i < MOD; i++) {
        f[i] = (f[i - 1] * i) % MOD;
    }
    
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        cout << comb(n - 1, k) * binpow(2, k - 1) % MOD << '\n';
    }
    
    return 0;
}