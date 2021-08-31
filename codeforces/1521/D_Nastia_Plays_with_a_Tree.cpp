//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 100500
#define MOD 1000000007

int n;
vector <int> adj[MAXN];
bool visited[MAXN];
bool removed[MAXN];
bool isleaf[MAXN];
vector <vector <int>> ans;
vector <vector <int>> ans2;
int leaf;

void dfs_remove(int node) {
    visited[node] = true;
    int node_size = 0;
    for(int next: adj[node]) {
        if(removed[next]) continue;
        node_size += 1;
    }
    if(node_size > 2) {
        sort(adj[node].begin(), adj[node].end());
        int i = 0;
        for(int next: adj[node]) {
            if(!removed[next]) {
                i += 1;
                if(i > 2) {
                    removed[next] = true;
                    ans.push_back({node, next});
                    isleaf[next] = false;
                }
            }
        }
    }
    for(int next: adj[node]) {
        if(!visited[next]) {
            dfs_remove(next);
        }
    }
}

void dfs_find(int node) {
    visited[node] = true;
    int s = 0;
    for(int next: adj[node]) {
        if(!removed[next]) {
            s += 1;
        }
    }
    if(s==1) leaf = node;
    else {
        for(int next: adj[node]) {
            if(next == leaf) continue;
            if((!visited[next]) && (!removed[next])) {
                dfs_find(next);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    cin >> t;
while(t--) {
    ans.clear();
    ans2.clear();
    forn(i, MAXN) adj[i].clear();
    cin >> n;
    forn(i, n) {
        visited[i] = false;
        removed[i] = false;
        isleaf[i] = false;
    }
    forn(i, n-1) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1; i<=n; i++) {
        if(adj[i].size()==1) isleaf[i] = true;
    }
    dfs_remove(1);
    forn(i, n) {
        if(isleaf[i+1]) {
            leaf = i+1;
            break;
        }
    }
    forn(i, n) visited[i] = false;
    // cout << leaf << endl;
    forn(i, n) {
        if(removed[i+1]) {
            // cout << i << endl;
            ans2.push_back({leaf, i+1});
            removed[i+1] = false;
            dfs_find(i+1);
        }
    }
    int ans_size = 0;
    for(auto it: ans) ans_size += 1;
    cout << ans_size << endl;
    forn(i, ans_size) {
        ans[i].push_back(ans2[i][0]);
        ans[i].push_back(ans2[i][1]);
    }
    for(auto it: ans) {
        cout << it[0] << " " << it[1] << " " << it[3] << " " << it[2] << endl;
    }
}
    return 0;
}
