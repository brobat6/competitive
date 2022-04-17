#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int MAXN = 1000100;

vector<int> prime(MAXN);
vector<int> hs(MAXN, 0);

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
        tree[node] = 0;
        lazy[node] = 0;
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
        tree[node*2] ^= (sz[node*2]%2==0 ? 0 : lazy[node]);
        tree[node*2 + 1] ^= (sz[node*2 + 1]%2==0 ? 0 : lazy[node]);
        lazy[node*2] ^= lazy[node];
        lazy[node*2 + 1] ^= lazy[node];
        lazy[node] = 0;
    }
 
    void update_range(int node, int start, int end, int l, int r, T val) {
        if(start == end) {
            tree[node] ^= val;
            lazy[node] = 0;
            return;
        }
        if(l == start && r == end) {
            tree[node] ^= (end - start + 1 % 2 == 0 ? 0 : val);
            lazy[node] ^= val;
        } else {
            push(node);
            int mid = (start + end)/2;
            if(l <= mid) update_range(node * 2, start, mid, l, min(r, mid), val);
            if(r > mid) update_range(node * 2 + 1, mid + 1, end, max(l, mid + 1), r, val);
            tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
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
        return a ^ b;
    }
};

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("0.in", "r", stdin);
    // freopen("0_cpp.out", "w", stdout);

    
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    for(int i = 0; i <= MAXN; i++) {
        prime[i] = i;
    }
    for(int i = 2; i <= MAXN; i++) {
        if(prime[i] == i) {
            for(int j = i; j <= MAXN; j += i) {
                prime[j] = min(prime[j], i);
            }
            hs[i] = rng();
        }
    }
    for(int i = 2; i <= MAXN; i++) {
        if(prime[i] == i) continue;
        int x = i;
        int y = 0;
        while(x != 1) {
            y ^= hs[prime[x]];
            x /= prime[x];
        }
        hs[i] = y;
    }
    int t;
    cin >> t;
    assert(t > 0 && t <= 10000);
    int sum_n = 0;
    int sum_q = 0;
    while(t--) {
        int print_count = 0;
        int n, q;
        cin >> n >> q;
        assert(1 <= n && n <= 100000 && 1 <= q && q <= 100000);
        sum_n += n;
        sum_q += q;
        SegTree<int> st(4*n);
        st.build(1, 0, n - 1);
        // cerr << "Hashes: ";
        // for(int i = 0; i < n; i++) {
        //     cerr << st.query(1, 0, n - 1, i, i) << " ";
        // }
        // cerr << endl;
        for(int i = 0; i < q; i++) {
            int a; 
            cin >> a;
            assert(a >= 1 &&  a <= 2);
            if(a == 1) {
                int b, c, d;
                cin >> b >> c >> d;
                --b; --c;
                assert(b >= 0 && b < n && c >= 0 && c < n && d > 0 && d <= 1000000);
                st.update_range(1, 0, n - 1, b, c, hs[d]);
            } else {
                print_count++;
                int b, c;
                cin >> b >> c;
                --b; --c;
                assert(b >= 0 && b < n && c >= 0 && c < n);
                int x = st.query(1, 0, n - 1, b, c);
                cout << (x == 0 ? "YES" : "NO") << endl;
            }
            // cerr << "Hashes: ";
            // for(int i = 0; i < n; i++) {
            //     cerr << st.query(1, 0, n - 1, i, i) << " ";
            // }
            // cerr << endl;
        }
        assert(print_count > 0);
    }
    assert(sum_n <= 200000 && sum_q <= 200000);
    return 0;
}