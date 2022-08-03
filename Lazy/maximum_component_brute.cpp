#include <bits/stdc++.h>
using namespace std;
#define int long long

class DSU {
public:
    int n;
    vector <int> p, sz;
    multiset <int> ms;

    DSU(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        sz.resize(n, 1);
        for(int i = 0; i < n; i++) {
            ms.insert(1);
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
            ms.erase(ms.find(sz[c]));
            ms.erase(ms.find(sz[d]));
            sz[c] += sz[d];
            ms.insert(sz[c]);
        }
    }

    int sum(int k) {
        // sum of largest k components.
        int ans = 0;
        auto it = --ms.end();
        for(int i = 0; i < k; i++) {
            ans += (*it);
            if(it == ms.begin()) break;
            --it;
        }
        return ans;
    }

    void debug() {
        for(auto i : ms) cerr << i << " ";
        cerr << '\n';
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    DSU d(n);
    for(int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if(type == 1) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            d.unite(x, y);
        } else {
            int k;
            cin >> k;
            cout << d.sum(k + 1) << '\n';
        }
        d.debug();
    }
    
    return 0;
}