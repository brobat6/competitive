#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = (int)1E9 + 7;

int binpow2(int a, int b) {
    if(b == 0) return 1;
    int res = binpow2(a, b>>1);
    return res * res % MOD * (b % 2 ? a : 1) % MOD;
}

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

    int N = 1000;    

    clock_t first = clock();
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N*2; j++) {
            ans = (ans + binpow(MOD - i - 1, MOD - j - 1)) % MOD;
        }
    }
    clock_t second = clock();
    ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N*2; j++) {
            ans = (ans + binpow2(MOD - i - 1, MOD - j - 1)) % MOD;
        }
    }
    clock_t third = clock();
    cout << "Iterative - " << (double)(second - first)/CLOCKS_PER_SEC << '\n';
    cout << "Recursive - " << (double)(third - second)/CLOCKS_PER_SEC << '\n';
    
    return 0;
}