#include <bits/stdc++.h>
using namespace std;
 
int n, k;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> sz;
long long ans;
vector<int> temp;

int FIND_SIZE(int node, int prev) {
    sz[node] = 1;
    for(auto next : adj[node]) {
        if(next != prev && !vis[next]) {
            sz[node] += FIND_SIZE(next, node);
        }
    }
    return sz[node];
}

int FIND_CENTROID(int node, int prev, int tree_size) {
    for(auto next : adj[node]) {
        if(next != prev && !vis[next] && sz[next] * 2 > tree_size) {
            return FIND_CENTROID(next, node, tree_size);
        }
    }
    return node;
}

void FIND_DEPTH(int node, int prev, int depth) {
    assert(depth < (int)temp.size());
    temp[depth]++;
    for(auto next : adj[node]) {
        if(next != prev && !vis[next]) {
            FIND_DEPTH(next, node, depth + 1);
        }
    }
}

void SOLVE(int node, int prev) {
    int size = FIND_SIZE(node, prev);
    int root = FIND_CENTROID(node, prev, size);

    vis[root] = true;
    FIND_SIZE(root, root);

    // Find the paths of length K, crossing through root. 
    vector<vector<int>> paths;
    for(auto next : adj[root]) {
        if(!vis[next]) {
            temp.clear(); temp.resize(sz[next] + 2, 0);
            FIND_DEPTH(next, root, 1);
            paths.push_back(temp);
        }
    }
    int m = paths.size();
    vector<int> path_sum(size, 0);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < (int)paths[i].size(); j++) {
            path_sum[j] += paths[i][j];
        }
    }
    long long two_subtrees = 0;
    long long one_subtree = 0;
    for(int i = 0; i < m; i++) {
        int x = paths[i].size();
        for(int j = 1; j < x; j++) {
            if(j < k && k - j < size) {
                if(k - j < x) {
                    two_subtrees += 1ll * paths[i][j] * (path_sum[k - j] - paths[i][k - j]);
                } else {
                    two_subtrees += 1ll * paths[i][j] * path_sum[k - j];
                }
            }
            if(k == j) {
                one_subtree += paths[i][j];
            }
        }
    }
    ans += two_subtrees/2 + one_subtree;
    paths.clear();

    for(auto next : adj[root]) {
        if(!vis[next]) {
            SOLVE(next, root);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k;
    adj.resize(n);
    vis.resize(n, false);
    sz.resize(n);
    ans = 0;
    temp.clear();

    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
 
    SOLVE(0, 0);
 
    cout << ans;
 
    return 0;
}