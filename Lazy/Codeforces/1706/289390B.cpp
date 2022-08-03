#include <bits/stdc++.h>
using namespace std;
#define int long long

class DSU {
public:
    int n;
    vector <int> p, sz;
    vector<set<int>> s;

    DSU(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        sz.resize(n, 1);
        s.resize(n);
        for(int i = 0; i < n; i++) s[i].insert(i);
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
            for(auto i : s[d]) s[c].insert(i);
        }
    }

    tuple<int, int, int> get(int y) {
        int x = find(y);
        return make_tuple(*s[x].begin(), *(--s[x].end()), s[x].size());
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    DSU d(n);
    for(int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if(s == "union") {
            int a, b;
            cin >> a >> b;
            --a; --b;
            d.unite(a, b);
        } else {
            int x;
            cin >> x;
            --x;
            auto [a, b, c] = d.get(x);
            cout << a + 1 << " " << b + 1 << " " << c << '\n';
        }
    }
    
    return 0;
}


/*

N nodes

M unite operations

How many times is the SET of a node expected to change?
O(Log N)

1 2 3 4 5

unite(1, 2) ---> the set of 2 changes (p[2] = 1)
unite(3, 4) --> the set of 4 changes (p[4] = 3)

unite(3, 5) --> the set of 5 will change (p[5] = 3)
// if I had changed 3 ---> set of 3 changes and MOREOVER set of 4 changes

// if I make parent[smaller] = greater
// then "smaller" nodes have their set changed
// but if I make parent[greater] = smaller
// then "greater" nodes have their set changed.


A node only changes its set when the size of set DOUBLES
sz[node] --> 5
sz[node after uniting] >= 10

Doubling can only be done Log N times


*/