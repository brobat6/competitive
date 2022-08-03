#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    int n;
    vector <int> parent;
    vector <int> sz;

    DSU(int x) {
        n = x;
        parent.resize(n);
        sz.resize(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) {
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        int c = find(a);
        int d = find(b);
        if(c != d) {
            if(sz[c] < sz[d]) swap(c, d); 
            parent[d] = c;
            sz[c] += sz[d];
        }
    }

    int size(int a) {
        return sz[find(a)];
    }
};