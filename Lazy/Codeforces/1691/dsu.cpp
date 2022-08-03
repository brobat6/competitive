#include <bits/stdc++.h>
using namespace std;
#define int long long

int find(int x) {
    if(x==parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    int c = find(a);
    int d = find(b);
    if(d!=c) parent[d] = c;
}

class DSU {
public:
    vector <int> p;
    vector <int> sz;

    DSU(int n) {
        p.resize(n);
        sz.resize(n);
        for(int i = 0; i < n; i++) {
            p[i] = i;
            sz[i] = 1;
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
            if(sz[d] > sz[c]) swap(c, d);
            p[d] = c;
            sz[c] += sz[d];
        }
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    
    return 0;
}