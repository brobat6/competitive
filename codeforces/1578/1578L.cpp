#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 100100;
const int MOD = 1000000007;

int n, m, t1, t2, t3, sum, root;
vector <pair<int, int>> adj[MAXN];
vector <vector<int>> edges;
int c[MAXN], parent[MAXN], down[MAXN], up[MAXN];
bool pos_curr[MAXN], pos_up[MAXN], pos_down[MAXN];

int find(int x) {
    if(x==parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b, int w) {
    int c = find(a);
    int d = find(b);
    if(d!=c) {
        parent[d] = c;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
        // cerr << "Edge " << w << "included!" << endl;
    }
}

bool comp(vector<int>& a, vector<int>& b) {
    return a[2] > b[2];
}

void dfs(int node, int prev) {
    if(adj[node].size()==1 && node != 0) {
        down[node] = 0;
    }
    for(auto next : adj[node]) {
        if(next.first == prev) continue;
        dfs(next.first, node);
        down[node] += down[next.first] + c[next.first];
    }
}

void dfs2(int node, int prev) {
    if(node==0) up[node] = 0;
    else {
        up[node] = up[prev] + down[prev] - down[node] - c[node] + c[prev];
    }
    for(auto next : adj[node]) {
        if(next.first == prev) continue;
        dfs2(next.first, node);
    }
}

bool check(int x) {
    
}

int binary_search(int left, int right) {
    int ans = -1;
    while(left <= right) {
        int mid = (left + right)/2;
        if(check(mid)) {
            left = mid + 1;
            ans = mid;
        }
        else {
            right = mid - 1;
        }
    }
    return ans;
}

void solve() {
    cin >> n >> m;
    sum = 0;
    forn(i, 0, n) {
        cin >> c[i];
        parent[i] = i;
        sum += c[i];
        down[i] = up[i] = 0;
    }
    forn(i, 0, m) {
        cin >> t1 >> t2 >> t3;
        --t1; --t2;
        edges.push_back({t1, t2, t3});
    }
    sort(edges.begin(), edges.end(), comp);
    for(auto i : edges) {
        unite(i[0], i[1], i[2]);
    }
    dfs(0, 0); dfs2(0, 0);
    forn(i, 0, n) cout << up[i] << " " << down[i] << endl;
    cout << binary_search(1, edges[0][2]);
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