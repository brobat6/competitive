#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

template <typename T>
class SegTree {
public:
    vector <T> tree;

    SegTree(int size) {
        tree.resize(size, 0);
    }

    T func(T a, T b) {
        return a + b; // Segment tree for the sum
        // return min(a, b); // Segment tree for the minimum
    }

    void update(int node, int start, int end, int pos) {
        if(start == end) {
            tree[node] = !tree[node]; // Assign value here.
        } else {
            int mid = (start + end)/2;
            if(pos <= mid) {
                update(node*2, start, mid, pos);
            } else {
                update(node*2 + 1, mid + 1, end, pos);
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

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    SegTree<int> st(4*n);
    for(int i = 1; i < n; i++) {
        if(s[i] != s[i - 1]) {
            st.update(1, 0, n - 1, i);
        }
    }
    for(int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a;
        if(a == 1) {
            cin >> b >> c;
            --b; --c;
            if(b != 0) st.update(1, 0, n - 1, b);
            if(c != n - 1) st.update(1, 0, n - 1, c + 1);
        }
        if(a == 2) {
            cin >> b >> c >> d;
            --b; --c; --d;
            if(b == c) {
                cout << "YES" << endl;
                continue;
            }
            int flips = st.query(1, 0, n - 1, b + 1, c);
            if(flips == 0 && d > b) {
                cout << "NO" << endl;
                continue;
            }
            if(flips == 0 && d == b) {
                cout << "YES" << endl;
                continue;
            }
            if(flips == 1) {
                if(d == b) {
                    cout << "NO" << endl;
                    continue;
                }
                if(st.query(1, 0, n - 1, d, d) == 1) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
                continue;
            } 
            cout << "YES" << endl;
        }
    }
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}