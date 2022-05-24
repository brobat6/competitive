#include <bits/stdc++.h>
using namespace std;

const int n = 256;
vector <int> parent(n);
vector <string> rep(n); // representation of the value in 8-bit.

bool check(string &x, string &y) {
    // check if x is just y rotated.
    vector<int> a(8), b(8);
    for(int i = 0; i < 8; i++) {
        a[i] = x[i] - '0';
        b[i] = y[i] - '0';
    }
    for(int i = 0; i < 8; i++) {
        bool check = true;
        for(int j = 0; j < 8; j++) {
            if(a[j] != b[j]) check = false;
        }
        if(check) return true;
        vector <int> c(8);
        for(int j = 0; j < 8; j++) {
            c[j] = a[(j + 1) % 8];
        }
        a = c;
    }
    return false;
}

int integer(vector <int> &b) {
    int x = 0;
    for(int i = 0; i < 8; i++) {
        x += (b[i]<<i);
    }
    return x;
}

int find(int x) {
    if(x==parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    int c = find(a);
    int d = find(b);
    if(d!=c) {
        if(rep[d] > rep[c]) swap(c, d);
        parent[d] = c;
    }
}

set <int> outcomes(int x, int y) {
    vector <int> a(8), b(8);
    for(int i = 0; i < 8; i++) {
        a[i] = rep[x][i] - '0';
        b[i] = rep[y][i] - '0';
    }
    set <int> out;
    for(int i = 0; i < 8; i++) {
        vector <int> z(8);
        for(int j = 0; j < 8; j++) {
            z[j] = a[j] ^ b[j];
        }
        int x = find(integer(z));
        if(x == 0 || x == n - 1) {}
        else out.insert(x);
        vector <int> c(8);
        for(int j = 0; j < 8; j++) {
            c[j] = b[(j + 1) % 8];
        }
        b = c;
    }
    return out;
}

void test() {
    int x = 1;
    int y = 127;
    vector <int> a(8), b(8);
    for(int i = 0; i < 8; i++) {
        a[i] = rep[x][i] - '0';
        b[i] = rep[y][i] - '0';
    }
    set <int> out;
    for(int i = 0; i < 8; i++) {
        vector <int> z(8);
        for(int j = 0; j < 8; j++) {
            z[j] = a[j] ^ b[j];
            cout << b[j];
        }
        cout << '\n';
        int x = find(integer(z));
        if(x == 0 || x == n - 1) {}
        else out.insert(x);
        cout << integer(z) << " " << x << '\n';
        vector <int> c(8);
        for(int j = 0; j < 8; j++) {
            c[j] = b[(j + 1) % 8];
        }
        b = c;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for(int i = 0; i < n; i++) {
        string x;
        for(int j = 0; j < 8; j++) {
            x += '0' + ((i>>j) & 1);
        }
        rep[i] = x;
    }
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(check(rep[i], rep[j])) {
                unite(i, j);
            }
        }
    }
    vector<vector<pair<int, int>>> adj(n); // it is possible to go from i to adj[i].second by querying adj[i].first
    for(int i = 1; i < n; i++) {
        if(i != parent[i]) continue;
        for(int j = 1; j < n - 1; j++) {
            if(j != parent[j]) continue;
            // what happens if we send j as a query, and the current number is i.
            // It's only valid if for every number of bits, we can reach only one unique state. ??
            // see if we can convert j to some other state by sending the number i.
            auto x = outcomes(i, j);
            // if((int)x.size() == 1) cout << i << " " << j << " " << (*x.begin()) << '\n';
            if((int)x.size() == 1) {
                int y = *x.begin();
                adj[i].push_back({j, y});
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(i != parent[i]) continue;
        cout << i << " ";
        for(auto j : adj[i]) cout << "{" << j.first << "," << j.second << "} ";
        cout << '\n';
    }

    test();
    
    return 0;
}