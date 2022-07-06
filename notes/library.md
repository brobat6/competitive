# Reference Library for ICPC

**By : Tanveer Singh (@brobat)**


- [Reference Library for ICPC](#reference-library-for-icpc)
    - [Template](#template)
    - [Binary Exponentiation](#binary-exponentiation)
    - [Compute GCD using Euclidean Algorithm](#compute-gcd-using-euclidean-algorithm)
    - [Finding $N^{th}$ Fibonacci Number in $O(Log N)$](#finding-nth-fibonacci-number-in-olog-n)
    - [Sieve of Eratosthenes](#sieve-of-eratosthenes)
    - [Linear Sieve (SPF)](#linear-sieve-spf)
    - [Deterministic Miller-Rabin Primality Test](#deterministic-miller-rabin-primality-test)
    - [Euler Phi Function](#euler-phi-function)
    - [Modular Inverse](#modular-inverse)
    - [Gray Code and Inverse Gray Code](#gray-code-and-inverse-gray-code)
    - [Sparse table for RMQ in O(1)](#sparse-table-for-rmq-in-o1)
    - [DSU](#dsu)

### Template

```c++
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 200100;
const int MOD = (int)1E9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    
    return 0;
}
```

### Binary Exponentiation

```c++
int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res % MOD;
}
```

### Compute GCD using Euclidean Algorithm

```c++
int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}
```

### Finding $N^{th}$ Fibonacci Number in $O(Log N)$

```c++
pair<int, int> fib (int n) {
    // returns F_n and F_(n + 1)
    if (n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    int c = p.first * (2 * p.second - p.first);
    int d = p.first * p.first + p.second * p.second;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}
```

### Sieve of Eratosthenes

```c++
vector <bool> is_prime(N + 1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i * i <= N; i++) {
    if (is_prime[i]) {
        for (int j = i * i; j <= N; j += i)
            is_prime[j] = false;
    }
}
```

### Linear Sieve (SPF)

```c++
vector<int> spf(N + 1);
vector<int> pr;

for(int i = 2; i <= N; i++) {
    if (spf[i] == 0) {
        spf[i] = i;
        pr.push_back(i);
    }
    for (int j = 0; j < (int)pr.size() && pr[j] <= spf[i] && i*pr[j] <= N; ++j) {
        spf[i * pr[j]] = pr[j];
    }
}
```

### Deterministic Miller-Rabin Primality Test

```c++
using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}
```

### Euler Phi Function

```c++
int phi(int n) {
    // O(sqrt(N))
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

void phi_1_to_n(int n) {
    // O(N Log(Log(N)))
    vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
```

### Modular Inverse

```c++
int inverse(int a, int m) {
    int u = 0, v = 1;
    while (a != 0) {
        int t = m / a;
        m -= t * a; swap(a, m);
        u -= t * v; swap(u, v);
    }
    assert(m == 1);
    return u;
}

int inverse(int x) {
    return binpow(x, MOD - 2);
}
```

### Gray Code and Inverse Gray Code

```c++
int g (int n) {
    return n ^ (n >> 1);
}

int rev_g (int g) {
    int n = 0;
    for (; g; g >>= 1)
        n ^= g;
    return n;
}
```

### Sparse table for RMQ in O(1)

.

### DSU

```c++
class DSU {
public:
    vector <int> p, sz;
    int n;

    DSU(int x) {
        n = x;
        p.resize(n);
        sz.resize(n);
        for(int i = 0; i < n; i++) {
            sz[i] = 1;
            p[i] = i;
        }
    }

    int find(int x) {
        if(x == p[x]) return x;
        return p[x] = find(p[x]);
    }

    void unite(int a, int b) {
        int c = find(a);
        int d = find(b);
        if(d != c) {
            if(sz[c] < sz[d]) swap(c, d);
            p[d] = c;
            sz[c] += sz[d];
        }
    }
}
```

