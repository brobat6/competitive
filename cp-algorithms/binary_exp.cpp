#include <iostream>
#define MOD 1000000007
using namespace std;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res%MOD;
}

int main() {
    cout << binpow(7, 1000000) << endl;
}