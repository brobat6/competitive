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
    - [Fenwick Tree](#fenwick-tree)
    - [Segment Tree](#segment-tree)
    - [Segment Tree - Add on Range Update, Min on Range Query](#segment-tree---add-on-range-update-min-on-range-query)
    - [Segment Tree - Add on Range Update, Sum on Range Query](#segment-tree---add-on-range-update-sum-on-range-query)
    - [Segment Tree - Assignment on Range Update, Minimum on Range Query](#segment-tree---assignment-on-range-update-minimum-on-range-query)
    - [Segment Tree - Assignment on Range Update, Sum on Range Query](#segment-tree---assignment-on-range-update-sum-on-range-query)
    - [Segment Tree - Arithmetic Progression](#segment-tree---arithmetic-progression)
    - [Trie](#trie)

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

### Fenwick Tree

.

### Segment Tree

```c++
template <typename T>
class SegTree {
public:
    vector <T> tree;

    SegTree(int size) {
        tree.resize(size);
    }

    T func(T a, T b) {
        return a + b; // Segment tree for the sum
        // return min(a, b); // Segment tree for the minimum
    }

    void build(int node, int start, int end, vector <T> &v) {
        if(start == end) {
            tree[node] = v[start];
        } else {
            int mid = (start + end)/2;
            build(2*node, start, mid, v);
            build(2*node + 1, mid + 1, end, v);
            tree[node] = func(tree[node*2], tree[node*2 + 1]);
        }
    }

    void update(int node, int start, int end, int pos, T val) {
        if(start == end) {
            tree[node] = val; // Assign value here.
        } else {
            int mid = (start + end)/2;
            if(pos <= mid) {
                update(node*2, start, mid, pos, val);
            } else {
                update(node*2 + 1, mid + 1, end, pos, val);
            }
            tree[node] = func(tree[node*2], tree[node*2 + 1]);
        }
    }

    T query(int node, int start, int end, int l, int r) {
        if(l > r) {
            return 0; // Return appropriate value, for example INF for minimum.
        }
        if(l == start && r == end) {
            return tree[node];
        }
        int mid = (start + end)/2;
        return func(query(node*2, start, mid, l, min(mid, r)), query(node*2 + 1, mid + 1, end, max(l, mid + 1), r));
    }
};
```

### Segment Tree - Add on Range Update, Min on Range Query

Also works for
* Add on range update, max on range query
* Multiply on range update, sum on range query
* AND on range update, OR on range query

```c++
template <typename T>
class SegTree {
public:
    vector <T> tree;
    vector <T> lazy;
 
    SegTree(int size) {
        tree.resize(size);
        lazy.resize(size);
    }
 
    void push(int node) {
        tree[node * 2] += lazy[node];
        tree[node * 2 + 1] += lazy[node];
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
        lazy[node] = 0;
    }
 
    void update_range(int node, int start, int end, int l, int r, T val) {
        // Add val to [l, r].
        if(start == end) {
            tree[node] += val;
            lazy[node] = 0;
            return;
        }
        if(l == start && r == end) {
            tree[node] += val;
            lazy[node] += val;            
        } else {
            push(node);
            int mid = (start + end)/2;
            if(l <= mid) update_range(node * 2, start, mid, l, min(r, mid), val);
            if(r > mid) update_range(node * 2 + 1, mid + 1, end, max(l, mid + 1), r, val);
            tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
        }
    }
 
    T query(int node, int start, int end, int l, int r) {
        if(start == end) {
            return tree[node];
        }
        if(l == start && r == end) {
            return tree[node];
        }
        push(node);
        int mid = (start + end)/2;
        int a = 1E18, b = 1E18;
        if(l <= mid) a = query(node * 2, start, mid, l, min(r, mid));
        if(r > mid) b = query(node * 2 + 1, mid + 1, end, max(l, mid + 1), r);
        return min(a, b);
    }
};
```

### Segment Tree - Add on Range Update, Sum on Range Query

```c++
template <typename T>
class SegTree {
public:
    vector <T> tree;
    vector <T> lazy;
    vector <int> sz;
 
    SegTree(int size) {
        tree.resize(size);
        lazy.resize(size);
        sz.resize(size);
    }
 
    void build(int node, int start, int end) {
        if(start == end) {
            sz[node] = 1;
        } else {
            int mid = (start + end)/2;
            build(node*2, start, mid);
            build(node*2 + 1, mid + 1, end);
            sz[node] = end - start + 1;
        }
    }
 
    void push(int node) {
        tree[node*2] += (lazy[node] * sz[node*2]);
        tree[node * 2 + 1] += (lazy[node] * sz[node*2 + 1]);
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
        lazy[node] = 0;
    }
 
    void update_range(int node, int start, int end, int l, int r, T val) {
        // Add val to [l, r].
        if(start == end) {
            tree[node] += val;
            lazy[node] = 0;
            return;
        }
        if(l == start && r == end) {
            tree[node] += val * (end - start + 1);
            lazy[node] += val;
        } else {
            push(node);
            int mid = (start + end)/2;
            if(l <= mid) update_range(node * 2, start, mid, l, min(r, mid), val);
            if(r > mid) update_range(node * 2 + 1, mid + 1, end, max(l, mid + 1), r, val);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }
 
    T query(int node, int start, int end, int l, int r) {
        if(start == end) {
            return tree[node];
        }
        if(l == start && r == end) {
            return tree[node];
        }
        push(node);
        int mid = (start + end)/2;
        int a = 0, b = 0;
        if(l <= mid) a = query(node * 2, start, mid, l, min(r, mid));
        if(r > mid) b = query(node * 2 + 1, mid + 1, end, max(l, mid + 1), r);
        return a + b;
    }
};
```

### Segment Tree - Assignment on Range Update, Minimum on Range Query

```c++
template <typename T>
class SegTree {
public:
    vector <T> tree;
    vector <T> lazy;
    vector <bool> marked;
 
    SegTree(int size) {
        tree.resize(size);
        lazy.resize(size);
        marked.resize(size, false);
    }
 
    void push(int node) {
        tree[node*2] = lazy[node];
        tree[node*2 + 1] = lazy[node];
        lazy[node*2] = lazy[node];
        lazy[node*2 + 1] = lazy[node];
        marked[node*2] = true;
        marked[node*2 + 1] = true;
        marked[node] = false;
    }
 
    void update_range(int node, int start, int end, int l, int r, T val) {
        // Add val to [l, r].
        if(start == end) {
            tree[node] = val;
            marked[node] = false;
            return;
        }
        if(l == start && r == end) {
            tree[node] = val;
            lazy[node] = val;
            marked[node] = true;
        } else {
            if(marked[node]) push(node);
            int mid = (start + end)/2;
            if(l <= mid) update_range(node * 2, start, mid, l, min(r, mid), val);
            if(r > mid) update_range(node * 2 + 1, mid + 1, end, max(l, mid + 1), r, val);
            tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
        }
    }
 
    T query(int node, int start, int end, int l, int r) {
        if(start == end) {
            return tree[node];
        }
        if(l == start && r == end) {
            return tree[node];
        }
        if(marked[node]) push(node);
        int mid = (start + end)/2;
        int a = 1E18, b = 1E18;
        if(l <= mid) a = query(node * 2, start, mid, l, min(r, mid));
        if(r > mid) b = query(node * 2 + 1, mid + 1, end, max(l, mid + 1), r);
        return min(a, b);
    }
};
```

### Segment Tree - Assignment on Range Update, Sum on Range Query

```c++
template <typename T>
class SegTree {
public:
    vector <T> tree;
    vector <T> lazy;
    vector <bool> marked;
    vector <int> sz;
 
    SegTree(int size) {
        tree.resize(size);
        lazy.resize(size);
        marked.resize(size, false);
        sz.resize(size);
    }
 
    void build(int node, int start, int end) {
        if(start == end) {
            sz[node] = 1;
        } else {
            int mid = (start + end)/2;
            build(node*2, start, mid);
            build(node*2 + 1, mid + 1, end);
            sz[node] = end - start + 1;
        }
    }
 
    void push(int node) {
        tree[node*2] = (lazy[node] * sz[node * 2]);
        tree[node*2 + 1] = (lazy[node] * sz[node * 2 + 1]);
        lazy[node*2] = lazy[node];
        lazy[node*2 + 1] = lazy[node];
        marked[node*2] = true;
        marked[node*2 + 1] = true;
        marked[node] = false;
    }
 
    void update_range(int node, int start, int end, int l, int r, T val) {
        // Add val to [l, r].
        if(start == end) {
            tree[node] = val;
            marked[node] = false;
            return;
        }
        if(l == start && r == end) {
            tree[node] = val * (end - start + 1);
            lazy[node] = val;
            marked[node] = true;
        } else {
            if(marked[node]) push(node);
            int mid = (start + end)/2;
            if(l <= mid) update_range(node * 2, start, mid, l, min(r, mid), val);
            if(r > mid) update_range(node * 2 + 1, mid + 1, end, max(l, mid + 1), r, val);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }
 
    T query(int node, int start, int end, int l, int r) {
        if(l == start && r == end) {
            return tree[node];
        }
        if(marked[node]) push(node);
        int mid = (start + end)/2;
        int a = 0, b = 0;
        if(l <= mid) a = query(node * 2, start, mid, l, min(r, mid));
        if(r > mid) b = query(node * 2 + 1, mid + 1, end, max(l, mid + 1), r);
        return a + b;
    }
};
```

### Segment Tree - Arithmetic Progression

.

### Trie
Represent a Trie using a struct.

```c++
#define M 26

struct Trie {
    Trie* bit[M];
    bool endOfWord = false;
};
Trie* root;
```
Insertion operation in a Trie.
```c++
void insert(string word) {
    Trie* temp = root;
    for(auto ch : word) {
        int b = ch - 'a';
        if(!temp->bit[b]) {
            temp->bit[b] = new Trie();
        }
        temp = temp->bit[b];
    }
    temp->endOfWord = true;
}
```
Search if a string is present in a Trie.
```c++
bool search(string word) {
	Trie* temp = root;
	for(auto ch : word) {
		int b = ch - 'a';
		if(!temp->bit[b]) return false;
		temp = temp->bit[b];
	}
	if(temp->endOfWord) return true;
	return false;
}
```

Problem : Finding maximum XOR of a given number in an array.

```c++
struct Trie {
    Trie* bit[2];
    int data = -1;
};
    
Trie* root;
    
void insert(int n) {
    Trie* temp = root;
    for(int i = 0; i < 31; i++) {
        int b = (n >> (30 - i)) & 1;
        if(!temp->bit[b]) {
            temp->bit[b] = new Trie();
        }
        temp = temp->bit[b];
    }
    temp->data = n;
}
    
int max_xor(int n) {
    Trie* temp = root;
    for(int i = 0; i < 31; i++) {
        int b = (n >> (30 - i)) & 1;
        if(!temp->bit[!b]) {
            temp = temp->bit[b];
        }
        else {
            temp = temp->bit[!b];
        }
    }
    return n^(temp->data);
}
```

