# Reference Library for ICPC

**By : Tanveer Singh (@brobat)**


- [Reference Library for ICPC](#reference-library-for-icpc)
  - [Important Stuff](#important-stuff)
    - [Template](#template)
    - [Binary Exponentiation](#binary-exponentiation)
    - [Y Combinator](#y-combinator)
    - [Pragma](#pragma)
    - [Faster unordered_map](#faster-unordered_map)
    - [Random number Generator](#random-number-generator)
    - [Ordered Set](#ordered-set)
    - [Custom Comparators](#custom-comparators)
  - [Reference](#reference)
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
    - [String algorithms](#string-algorithms)
    - [Ternary Search](#ternary-search)
    - [Find bridges in a graph](#find-bridges-in-a-graph)
    - [Finding Articulation Points in a Graph](#finding-articulation-points-in-a-graph)
    - [Finding Strongly Connected Components in a Graph](#finding-strongly-connected-components-in-a-graph)
    - [Dijkstra](#dijkstra)
    - [Bellman-Ford](#bellman-ford)
    - [0-1 BFS](#0-1-bfs)
    - [Floyd-Warshall Algorithm](#floyd-warshall-algorithm)
    - [Lowest Common Ancestor](#lowest-common-ancestor)
    - [NTT](#ntt)


## Important Stuff

### Template
Snippet : cppbasic
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
Snippet : binpow
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

### Y Combinator
Snippet : ycomb
```c++
template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
```

### Pragma

```c++
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
```

### Faster unordered_map

The following lines of code let us use a faster unordered_map in C++. 

```c++
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef cc_hash_table<int, int, hash<int>> ht;
```

### Random number Generator

The following lines of code let us add a high quality random number generator in C++.

```c++
#include<bits/stdc++.h>
using namespace std;

int main() {
    mt19937 rng_32(chrono::steady_clock::now().time_since_epoch().count()); // 32 bit random nos
    mt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count()); // 64 bit random nos
    cout << rng(); // Generating a random no
    vector <int> arr;
    shuffle(arr.begin(), arr.end(), rng); // Randomly shuffling a permutation
}
```

### Ordered Set 

https://www.geeksforgeeks.org/ordered-set-gnu-c-pbds/

It is a Policy Based data structure. It works as a normal set, but can support two more operations:
1. find_by_order(k) : Returns an iterator to the kth element (counting from zero) in the set in O(Log N) time.
2. order_of_key(k) : Returns the number of items that are **strictly** smaller than the item K in O(Log N) time.

The following lines of code need to be added : 

```c++
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
```

It can also be used as an Ordered Set of pairs. Just change the definition to 
```c++
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>
```

Example of some operations : 
```c++
    ordered_set X;
    X.insert(1);
    X.insert(2);
    X.insert(4);
    X.insert(8);
    X.insert(16);

    cout<<*X.find_by_order(1)<<endl; // 2
    cout<<*X.find_by_order(2)<<endl; // 4
    cout<<*X.find_by_order(4)<<endl; // 16
    cout<<(end(X)==X.find_by_order(6))<<endl; // true

    cout<<X.order_of_key(-5)<<endl;  // 0
    cout<<X.order_of_key(1)<<endl;   // 0
    cout<<X.order_of_key(3)<<endl;   // 2
    cout<<X.order_of_key(4)<<endl;   // 2
    cout<<X.order_of_key(400)<<endl; // 5
```

### Custom Comparators

Struct.
```c++
struct S {
    int a, b;

    bool operator <(const S & other) const {
        return (a + b) < (other.a + other.b);
    }
};
```

Priority Queue.
```c++
bool compare(T a, T b) {

}

priority_queue<T, vector<T>, function<bool(T, T)>> pq(comapre);
```

Set.
```c++
auto cmp = [](int a, int b) { return ... };
// For C++20:
std::set<int, decltype(cmp)> s;
// std::set<int, decltype(cmp)> s(cmp); 
```


## Reference

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

### String algorithms

.

### Ternary Search
Finding the maximum value of a function that first strictly increases, then strictly decreases

```c++
double ternary_search(double l, double r) {
    double eps = 1e-9;              //set the error limit here
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);      //evaluates the function at m1
        double f2 = f(m2);      //evaluates the function at m2
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    return f(l);                    //return the maximum of f(x) in [l, r]
}
```

### Find bridges in a graph

For an undirected graph, a bridge is an edge, which, when removed, increases the number of components in the graph.

Time Complexity : $O(N + M)$.

We can replace the `IS_BRIDGE(v, to)` with whatever we want, for example, push_back to a vector. 

```c++
int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}
```

### Finding Articulation Points in a Graph

For an undirected graph, an articulation point is a vertex, which, when removed alongwith all associated edges, increases the number of components in the graph.

Time Complexity : $O(N + M)$.

We can replace the `IS_CUTPOINT(v)` with whatever we want, for example, push_back to a vector. 

```c++
int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                IS_CUTPOINT(v);
            ++children;
        }
    }
    if(p == -1 && children > 1)
        IS_CUTPOINT(v);
}

void find_cutpoints() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i);
    }
}
```

### Finding Strongly Connected Components in a Graph

Time Complexity : $O(N + M)$

```c++
vector<vector<int>> adj, adj_rev;
vector<bool> used;
vector<int> order, component;

void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}

int main() {
    int n;
    // ... read n ...

    for (;;) {
        int a, b;
        // ... read next directed edge (a,b) ...
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }

    used.assign(n, false);

    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);

    used.assign(n, false);
    reverse(order.begin(), order.end());

    for (auto v : order)
        if (!used[v]) {
            dfs2 (v);

            // ... processing next component ...

            component.clear();
        }
}
```

### Dijkstra

Finds shortest paths from a source, given a weighted graph with non-negative weights. 

Time Complexity : $O(E Log V)$

```c++
const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    set<pair<int, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}
```

### Bellman-Ford

Single source shortest paths in a weighted graph with negative weights

```c++
struct edge
{
    int a, b, cost;
};

int n, m, v;
vector<edge> e;
const int INF = 1000000000;

void solve()
{
    vector<int> d (n, INF);
    d[v] = 0;
    for (int i=0; i<n-1; ++i)
        for (int j=0; j<m; ++j)
            if (d[e[j].a] < INF)
                d[e[j].b] = min (d[e[j].b], d[e[j].a] + e[j].cost);
    // display d, for example, on the screen
}
```

### 0-1 BFS

Single source shortest paths in case the weight of every edge in a weighted graph is either 0 or 1.

Time Complexity : $O(V + E)$.

```c++
vector<int> d(n, INF);
d[s] = 0;
deque<int> q;
q.push_front(s);
while (!q.empty()) {
    int v = q.front();
    q.pop_front();
    for (auto edge : adj[v]) {
        int u = edge.first;
        int w = edge.second;
        if (d[v] + w < d[u]) {
            d[u] = d[v] + w;
            if (w == 1)
                q.push_back(u);
            else
                q.push_front(u);
        }
    }
}
```

### Floyd-Warshall Algorithm

Given a directed or an undirected weighted graph $G$ with $n$ vertices. The task is to find the length of the shortest path $d_{i,j}$ between each pair of vertices $i$ and $j$.

The graph may have negative weight edges, but no negative weight cycles.

Time Complexity : $O(N^3)$.

Initially set the $d[][]$ matrix to the initial weights of the edges, $d[i][i] = 0$ and the rest to $INF$.

```c++
for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
        }
    }
}
```

### Lowest Common Ancestor

Using Binary Lifting

```c++
int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}
```

### NTT

Multiply two polynomials of degree $N$ in $O(N Log N)$.

```c++
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll mod = (119 << 23) + 1, root = 62; // = 998244353
// For p < 2^30 there is also e . g . 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root) . The last two are > 10^9.
typedef vector<ll> vl;

void ntt(vl &a) {
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vl rt(2, 1);
    for (static int k = 2, s = 2; k < n; k *= 2, s++) {
        rt.resize(n);
        ll z[] = {1, modpow(root, mod >> s)};
        rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
    }
    vi rev(n);
    rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
            ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
            a[i + j + k] = ai - z + (z > ai ? mod : 0);
            ai += (ai + z >= mod ? z - mod : z);
        }
}

vl conv(const vl &a, const vl &b) {
    if (a.empty() || b.empty()) return {};
    int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
    int inv = modpow(n, mod - 2);
    vl L(a), R(b), out(n);
    L.resize(n), R.resize(n);
    ntt(L), ntt(R);
    rep(i,0,n) out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
    ntt(out);
    return {out.begin(), out.begin() + s};
}
```

