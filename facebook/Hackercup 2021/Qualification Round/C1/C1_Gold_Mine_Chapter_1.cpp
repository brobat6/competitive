#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 55
#define MOD 1000000007

int n, t1, t2;
vector <int> adj[MAXN];
bool visited[MAXN];
int cost[MAXN];
vector <pair<int, int>> first_ans;
vector <int> second_ans;
int ans;
int dist[MAXN];

void dfs(int node, int prev, int c) {
    if(adj[node].size()==1 && node != 0) {
        first_ans.push_back({c, node});
        return;
    }
    for(auto next : adj[node]) {
        if(next!=prev) {
            dfs(next, node, c + cost[next]);
        }
    }
}

void bfs(int start) {
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto next : adj[curr]) {
            if(dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
}

void dfs3(int node, int prev, int c) {
    if(adj[node].size()==1 && node != 0) {
        second_ans.push_back(c);
        return;
    }
    for(auto next : adj[node]) {
        if(next!=prev) {
            dfs3(next, node, c + cost[next]);
        }
    }
}

void dfs2(int node) {
    visited[node] = true;
    for(auto next : adj[node]) {
        if(dist[next] < dist[node]) {
            dfs2(next);
        }
    }
}

void pre() {
    cin >> n;
    forn(i, 0, n) {
        adj[i].clear();
        visited[i] = false;
        cost[i] = 0;
    }
    forn(i, 0, n) cin >> cost[i];
    forn(i, 0, n-1) {
        cin >> t1 >> t2;
        adj[--t1].push_back(--t2);
        adj[t2].push_back(t1);
    }
    first_ans.clear();
    second_ans.clear();
    second_ans.push_back(0);
    ans = 0;
    forn(i, 0, n) dist[i] = -1;
}

void solve() {
    pre();
    if(n==1) {
        cout << cost[0] << endl;
        return;
    }
    dfs(0, 0, cost[0]);
    sort(first_ans.begin(), first_ans.end(), greater<pair<int, int>>());
    bfs(0);
    ans = first_ans[0].first;
    dfs2(first_ans[0].second);
    int to_be_deleted;
    forn(i, 0, adj[0].size()) if(visited[adj[0][i]]) to_be_deleted = i;
    adj[0].erase(adj[0].begin() + to_be_deleted);
    dfs3(0, 0, 0);
    sort(second_ans.begin(), second_ans.end(), greater<int>());
    cout << ans + second_ans[0] << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("gold_mine_chapter_1_input.txt", "r", stdin);
    // freopen("gold_mine_chapter_1_output.txt", "w", stdout);

    int T = 1;
    cin >> T;
    forn(I, 1, T+1) {
        cout << "Case #" << I << ": ";
        solve();
    }

    return 0;
}