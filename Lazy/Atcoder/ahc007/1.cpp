#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>

#define n 4
#define m 6

// #define n 400
// #define m 1995

struct Edge {
    int u, v, w;
    bool operator <(const Edge& s) const {
        return w < s.w;
    }
    bool operator ==(const Edge& s) const {
        return u == s.u && v == s.v;
    }
};

vector <int> parent(n), sz(n);

int find(int x) {
    if(x==parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    int c = find(a);
    int d = find(b);
    if(sz[c] < sz[d]) swap(c, d);
    if(d!=c) {
        parent[d] = c;
        sz[c] += sz[d];
    }
}

vector <Edge> e(m);
vector <pi> vertex(n);
vector <Edge> adopted;

int dist(int u, int v) {
    // Calculates distance betwee vertices u and v
    pi x = vertex[u];
    pi y = vertex[v];
    return round(sqrt((x.first - y.first)*(x.first - y.first) + (x.second - y.second)*(x.second - y.second)));
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    for(int i = 0; i < n; i++) {
        cin >> vertex[i].first >> vertex[i].second;
    }
    for(int i = 0; i < m; i++) {
        cin >> e[i].u >> e[i].v;
        e[i].w = dist(e[i].u, e[i].v) * 2; // Try to go for 2d now.
    }
    for(int i = 0; i < m; i++) {
        int l; cin >> l;
        Edge curr = e[i];
        curr.w = l;
        for(int j = 0; j < n; j++) {
            parent[j] = j;
            sz[j] = 1;
        }
        int cnt = 0;
        for(auto j : adopted) {
            if(find(j.u) != find(j.v)) {
                cnt++;
                unite(j.u, j.v);
            }
        }
        // Construct MST from remaining edges and see if current Edge comes in MST or not.
        bool comes = false;
        vector <Edge> temp;
        temp.push_back(curr);
        for(int j = i + 1; j < m; j++) {
            temp.push_back(e[j]);
        }
        sort(temp.begin(), temp.end());
        for(auto j : temp) {
            if(cnt >= n - 1) break;
            if(find(j.u) != find(j.v)) {
                unite(j.u, j.v);
                cnt++;
                if(j == curr) {
                    comes = true;
                }
            }
        }
        if(comes) {
            cout << 1 << endl;
            adopted.push_back(curr);
        } else {
            cout << 0 << endl;
        }

    }
    
    return 0;
}