#include <bits/stdc++.h>
using namespace std;
 
class DSU {
public:
    int n;
    vector <int> p, sz;
 
    DSU(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        sz.resize(n, 1);
    }
 
    int find(int x) {
        if(x == p[x]) return x;
        return p[x] = find(p[x]);
    }
 
    bool unite(int a, int b) {
        int c = find(a);
        int d = find(b);
        if(d != c) {
            if(sz[c] < sz[d]) swap(c, d);
            p[d] = c;
            sz[c] += sz[d];
            return true;
        }
        return false;
    }
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    int l = ceil(log2(n)) + 1;
    vector<vector<int>> g(n), nx(n, vector<int>(l, 0));
    DSU d(n);
    vector <int> temp;
    map <int, int> m; // m[component] = root.
    for(int i = 0; i < n; i++) {
        int t; cin >> t; --t;
        nx[i][0] = t;
        if(!d.unite(i, t)) {
            temp.push_back(i);
        } else {
            g[t].push_back(i);
        }
    }
    for(auto i : temp) m[d.find(i)] = i;
    queue <int> qq;
    vector <int> depth(n, -1);
    for(auto i : m) {
        depth[i.second] = 0;
        qq.push(i.second);
    }
    while(!qq.empty()) {
        int curr = qq.front();
        qq.pop();
        for(auto nx : g[curr]) {
            depth[nx] = depth[curr] + 1;
            qq.push(nx);
        }
    }
    for(int i = 1; i < l; i++) {
        for(int j = 0; j < n; j++) {
            nx[j][i] = nx[nx[j][i - 1]][i - 1];
        }
    }
 
    auto GO_UP = [&](int x, int k) -> int {
        for(int j = 0; j < l; j++) {
            if((k >> j) & 1) {
                x = nx[x][j];
            }
        }
        return x;
    };
 
    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        if(d.find(a) != d.find(b)) {
            cout << -1 << '\n';
            continue;
        }
        // Case 1 : go up and check
        if(depth[a] >= depth[b]) {
            if(GO_UP(a, depth[a] - depth[b]) == b) {
                cout << depth[a] - depth[b] << '\n';
                continue;
            }
        }
        // Case 2 : go to root and cycle and check
        int c = nx[m[d.find(a)]][0];
        if(depth[c] >= depth[b]) {
            if(GO_UP(c, depth[c] - depth[b]) == b) {
                cout << depth[a] + 1 + depth[c] - depth[b] << '\n';
                continue;
            }
        }
        cout << -1 << '\n';
    }
 
    // for(int i = 0; i < n; i++) {
    //     cout << i + 1 << ": ";
    //     for(auto j : g[i]) cout << j + 1 << " ";
    //     cout << '\n';
    // }
    // for(auto i : m) {
    //     cout << i.first + 1 << " " << i.second + 1 << " " << nx[i.second][0] + 1 << '\n';
    // }
 
    return 0;
}