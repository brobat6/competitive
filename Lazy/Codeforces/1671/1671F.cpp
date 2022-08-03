#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 998244353;
const int p = 998244353;

unsigned long long power(unsigned long long x,
                                  int y, int p)
{
    unsigned long long res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0)
    {
     
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 
// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n, 
                                            int p)
{
    return power(n, p - 2, p);
}
 
// Returns nCr % p using Fermat's little
// theorem.
unsigned long long comb(unsigned long long n,
                                 int r)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        cout << '\n';
        int n, k, x;
        cin >> n >> k >> x;
        if(k < x) {
            cout << 0;
            continue;
        }
        if(x == 0) {
            cout << (k == 0 ? 1 : 0);
            continue;
        }
        if(k == 0) {
            if(x == 0) cout << 1;
            else cout << 0;
            continue;
        }
        if(k == x) {
            // DO IT
            continue;
        }
        if(k == 1) {
            if(x == 1) cout << n - 1;
            else cout << 0;
        }
        if(k == 2) {
            if(x == 1 && n >= 2) cout << 2*(n - 1) % MOD;
            else if(x == 2 && n >= 3) cout << comb(n - 1, 2) % MOD;
            else cout << 0;
        }
        if(k == 3) {
            
        }
    }
    
    return 0;
}