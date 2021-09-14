#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

struct Edge {
    int a, b, w;
    bool operator <(const Edge &b) const {
        return w < b.w;
    }
};
vector<Edge> edges;
int parent[MAXN];
int n, m, sum, mst;

int find(int x) {
    if(x==parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b, int w) {
    int c = find(a);
    int d = find(b);
    if(d!=c) {
        parent[d] = c;
        mst += w;
    }
}

void solve() {
    cin >> n >> m;
    edges.resize(m);
    sum = 0; mst = 0;
    forn(i, 0, n) parent[i] = i;
    forn(i, 0, m) {
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
        if(edges[i].w < 0) edges[i].w = 0;
        sum += edges[i].w;
        --edges[i].a; --edges[i].b;
    }
    sort(edges.begin(), edges.end());
    for(auto i : edges) {
        unite(i.a, i.b, i.w);
    }
    cout << sum - mst << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}