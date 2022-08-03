#include <bits/stdc++.h>
using namespace std;
#define int long long

template<int MOD = 998'244'353>
struct Mint {
    int val;
    Mint(long long v = 0) { if (v < 0) v = v % MOD + MOD; if (v >= MOD) v %= MOD; val = v; }
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1, q;
        while (r != 0) q = g / r, g %= r, swap(g, r), x -= q * y, swap(x, y);
        return x < 0 ? x + m : x;
    } 
    explicit operator int() const { return val; }
    explicit operator bool()const { return val; }
    Mint& operator+=(const Mint &o) { val += o.val; if (val >= MOD) val -= MOD; return *this; }
    Mint& operator-=(const Mint &o) { val -= o.val; if (val < 0) val += MOD; return *this; }
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
           #if !defined(_WIN32) || defined(_WIN64)
                return x % m;
           #endif
           unsigned x_high = x >> 32, x_low = (unsigned) x; unsigned quot, rem;
           asm("divl %4\n": "=a" (quot), "=d" (rem): "d" (x_high), "a" (x_low), "r" (m));
           return rem;
    }
    Mint& operator*=(const Mint &other) { val = fast_mod((uint64_t) val * other.val); return *this; }
    Mint& operator/=(const Mint &other) { return *this *= other.inv(); }
    friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
    friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
    friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
    friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
    Mint& operator++() { val=val==MOD-1?0:val+1; return *this; }
    Mint& operator--() { val=val==0?MOD-1:val-1; return *this; }
    Mint operator++(int32_t) { Mint before = *this; ++*this; return before; }
    Mint operator--(int32_t) { Mint before = *this; --*this; return before; }
    Mint operator-() const { return val == 0 ? 0 : MOD - val; }
    bool operator==(const Mint &other) const { return val == other.val; }
    bool operator!=(const Mint &other) const { return val != other.val; }
    Mint inv() const { return mod_inv(val); }
    Mint operator[](long long p) {
        assert(p >= 0);
        Mint a = *this, res = 1;
        while (p > 0) { if (p & 1) res *= a; a *= a, p >>= 1; }
        return res;
    }
    friend ostream& operator << (ostream &stream, const Mint &m) { return stream << m.val; }
    friend istream& operator >> (istream &stream, Mint &m) { return stream>>m.val; } 
};
using mint = Mint<>;

const int MOD = 998244353;

int inv_2;

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res % MOD;
}

class SegTree {
public:
    vector <int> tree;
    vector <pair<int, int>> lazy;
    vector <int> sz;
 
    SegTree(int size) {
        tree.resize(size, 0);
        lazy.resize(size, {0, 0});
        sz.resize(size, 0);
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

    int sum(int a, int d, int n) {
        return (a * 2 + (n - 1) * d) % MOD * n % MOD * inv_2 % MOD;
    }
 
    void push(int n) {
        int a = lazy[n].first;
        int d = lazy[n].second;
        int next_a = (a + (sz[n*2])*d) % MOD;
        tree[n*2] = (tree[n*2] + sum(a, d, sz[n*2])) % MOD;
        tree[n*2+1] = (tree[n*2+1] + sum(next_a, d, sz[n*2+1])) % MOD;
        lazy[n*2].first = (lazy[n*2].first + a) % MOD;
        lazy[n*2 + 1].first = (lazy[n*2 + 1].first + next_a) % MOD;
        lazy[n*2].second = (lazy[n*2].second + d) % MOD;
        lazy[n*2 + 1].second = (lazy[n*2 + 1].second + d) % MOD;
        lazy[n] = {0, 0};
    }
 
    void update_range(int node, int start, int end, int l, int r, int a, int d) {
        // Add AP to l, r
        if(start == end) {
            tree[node] = (tree[node] + sum(a, d, sz[node])) % MOD;
            lazy[node] = {0, 0};
            return;
        }
        if(l == start && r == end) {
            tree[node] = (tree[node] + sum(a, d, sz[node])) % MOD;
            lazy[node].first = (lazy[node].first + a) % MOD;
            lazy[node].second = (lazy[node].second + d) % MOD;
        } else {
            push(node);
            int mid = (start + end)/2;
            if(l <= mid) update_range(node * 2, start, mid, l, min(r, mid), a, d);
            int next_a;
            if(l > mid) next_a = a;
            else next_a = (a + (mid - l + 1)*d) % MOD;
            if(r > mid) update_range(node * 2 + 1, mid + 1, end, max(l, mid + 1), r, next_a, d);
            tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % MOD;
        }
    }
 
    int query(int node, int start, int end, int l, int r) {
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
        return (a + b) % MOD;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    inv_2 = binpow(2, MOD - 2);

    int n, q;
    cin >> n >> q;
    SegTree st(4*n);
    st.build(1, 0, n - 1);
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[i] = x;
        st.update_range(1, 0, n - 1, i, n - 1, x, x);
    }

    for(int i = 0; i < q; i++) {
        int a;
        cin >> a;
        if(a == 1) {
            int b, c;
            cin >> b >> c;
            --b;
            int delta = c - v[b];
            v[b] = c;
            delta = (delta + MOD) % MOD;
            st.update_range(1, 0, n - 1, b, n - 1, delta, delta);
        } else {
            int b;
            cin >> b;
            --b;
            cout << st.query(1, 0, n - 1, 0, b) << '\n';
        }
    }
    
    return 0;
}