//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 3050
#define MOD 1000000007

int n;
vector <int> adj[MAXN];
int depth[MAXN];
int parent[MAXN][14];
int dist[MAXN];
int dp[MAXN];

void bfs(int start) {
    queue <int> q;
    depth[start] = 0;
    q.push(start);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int e: adj[v]) {
            if(depth[e]==-1) {
                depth[e] = depth[v] + 1;
                q.push(e);
            }
        }
    }
}

void compute() {
    for(int i=1; i<14; i++) {
        forn(node, n) {
            if(parent[node][i-1] != 1) {
                parent[node][i-1] = parent[parent[node][i-1]][i-1];
            }
        }
    }
}

int lca(int u, int v) {
    if(depth[v] < depth[u]) swap(u, v);
    int diff = depth[v] - depth[u];
    forn(i, 14) {
        if((diff>>i)&1) v = parent[v][i];
    }
    if(u==v) return u;
    for(int i=13; i>=0; i--) {
        if(parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    scanf("%d", &t);
while(t--) {
    scanf("%d", &n);
    forn(i, n) {
        adj[i].clear();
        depth[i] = -1;
        forn(j, 20) parent[i][j] = -1;
        dist[i] = 0;
    }
    forn(i, n-1) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(0);
    forn(i, n) {
        for(auto node: adj[i]) {
            if(depth[node] < depth[i]) {
                parent[i][0] = node;
            }
        }
    }
    compute();
    forn(i, n) {
        for(int j=(i+1); j<n; j++) {
            int temp = lca(i, j);
            dist[depth[i] + depth[j] - (2*depth[temp]) - 1] += 1;
        }
    }
    long long ans = n;
    forn(i, n) {
        long long dummy = dist[i];
        if(dist[i] > 0) {
            dummy *= dp[i];
            dummy %= MOD;
        }
        ans += dummy;
        ans %= MOD;
    }
    printf("%d\n", ans);
}
    return 0;
}