#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    int c = (int)cbrt(n);
    map<int, int> m;
    for(int i = 2; i <= c; i++) {
        while(n % i == 0) {
            n /= i;
            m[i]++;
        }
    }
    // remaining number is either a prime or product of two primes.

    
    return 0;
}