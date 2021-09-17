#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 410;
const int MOD = 1000000007;

int n, m, t1, t2;
int dist[MAXN], ans[MAXN*MAXN];
map<pair<int, int>, int> edges;
vector<int> adj[MAXN], rev[MAXN];
vector<pair<int, int>> sp;

void bfs(int start, int a, int b) {
    memset(dist, -1, sizeof(dist));
    dist[start] = 0;
    queue <int> q;
    q.push(start);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto next : adj[curr]) {
            if(curr==a && next==b) continue;
            if(dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
}

void bfs_dist(int start) {
    queue<int> q;
    q.push(start);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto next : rev[curr]) {
            if(dist[next] != dist[curr] - 1) continue;
            sp.push_back({next, curr});
            q.push(next);
            break;
        }
    }
}

void solve() {
    cin >> n >> m;
    memset(ans, 0, sizeof(ans));
    forn(i, 0, m) {
        cin >> t1 >> t2;
        edges[{--t1, --t2}] = i;
        adj[t1].push_back(t2);
        rev[t2].push_back(t1);
    }
    bfs(0, 0, 0);
    bfs_dist(n-1);
    if(dist[n-1] == -1) {
        forn(i, 0, m) cout << -1 << endl;
        return;
    }
    int x = dist[n-1];
    for(auto i : sp) {
        bfs(0, i.first, i.second);
        ans[edges[i]] = dist[n-1];
    }
    forn(i, 0, m) if(ans[i]==0) ans[i] = x;
    forn(i, 0, m) cout << ans[i] << endl;
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