/*
    Solution approaches - 
    O(n * h): 
        While making a new node in the tree, update the farthest distance of all its ancestors
        While querying, for each ancestor of node, find largest distance
        h --> Height of the tree
    O(n * sqrt(n)):
        Use sqrt decomposition. Divide the queries into blocks of size m = sqrt(n)
        Everytime a block is completed, run a bottom-up DFS + top-down DFS to find the answer for every node
        (so that subsequent queries are O(1))
        While processing a block, for every new barn in the block, find the distance between the barns using LCA
        Technically this would be O(n * sqrt(n) * log(n))
        To speed up : Find the LCA of the FINAL tree in O(n * log(n)) and then using sparse-table solve LCA queries in O(1)
    O(n * log(n)):
        Centroid decomposition, basically an optimisation of the first O(n * h) approach as we are minimising the height of the tree.
        For each node, maintain two values - the farthest two distances in the centroid subtree of the node.
        Update barn - update distances of all ancestors in centroid tree
        Query - (farthest distance from ancestor + distance between ancestor and node), for all ancestors in centroid tree
        Will need to calculate LCA to find distances, so technically it would be O(n * log(n) * log(n)), 
        but once again it can be optimised using O(1) Sparse-Table type LCA 
    Approach implemented in this code : O(n * log(n) * log(n))

    Another cool solution:
        Observation: If T is a tree, and a, b are the endpoints of a diameter, than for any node u, 
        a or b is the furthest node from u. 
        Link : https://usaco.guide/problem-solutions/ (solution by Noe Weeks)
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1E9;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("newbarn.in", "r", stdin);
    freopen("newbarn.out", "w", stdout);
    
    int q;
    cin >> q;
    vector<pair<char, int>> query(q);
    vector<vector<int>> adj;
    int n = 0;
    for(int i = 0; i < q; i++) {
        cin >> query[i].first >> query[i].second;
        if(query[i].second >= 0) query[i].second--;
        if(query[i].first == 'B') {
            n++;
            while((int)adj.size() < n) adj.push_back({});
            if(query[i].second >= 0) {
                adj[n - 1].push_back(query[i].second);
                adj[query[i].second].push_back(n - 1);
            }
        }
    }
    vector <bool> vis(n, false);
    vector <int> p(n, -1), sz(n);
    vector <int> depth(n, -1);

    function<void(int, int, int)> FIND_DEPTH = [&](int node, int prev, int d) -> void {
        depth[node] = d;
        for(auto next : adj[node]) {
            if(next != prev) {
                FIND_DEPTH(next, node, d + 1);
            }
        }
    };

    function<int(int, int)> FIND_SIZE = [&](int node, int prev) -> int {
        sz[node] = 1;
        for(auto next : adj[node]) {
            if(next != prev && !vis[next]) {
                sz[node] += FIND_SIZE(next, node);
            }
        }
        return sz[node];
    };

    function<int(int, int, int)> FIND_CENTROID = [&](int node, int prev, int tree_size) -> int {
        for(auto next : adj[node]) {
            if(next != prev && !vis[next] && sz[next] * 2 > tree_size) {
                return FIND_CENTROID(next, node, tree_size);
            }
        }
        return node;
    };

    function<void(int, int)> MAKE_CENTROID_TREE = [&](int node, int prev) -> void {
        FIND_SIZE(node, prev);
        int root = FIND_CENTROID(node, prev, sz[node]);
        vis[root] = true;
        p[root] = prev;
        for(auto next : adj[root]) {
            if(!vis[next]) {
                MAKE_CENTROID_TREE(next, root);
            }
        }
    };

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            MAKE_CENTROID_TREE(i, -1);
        }
    }

    vector <int> comp;

    for(int i = 0; i < n; i++) {
        if(p[i] == -1) {
            comp.push_back(i);
            FIND_DEPTH(i, -1, 0);
        }
    }

    // Make functions to find LCA

    vector <int> tin(n), tout(n);
    int l = ceil(log2(n));
    int timer = 0;
    vector <vector<int>> up(n, vector<int>(l + 1));

    auto IS_ANCESTOR = [&](int u, int v) -> bool {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    };

    auto LCA = [&](int u, int v) -> int {
        if (IS_ANCESTOR(u, v))
            return u;
        if (IS_ANCESTOR(v, u))
            return v;
        for (int i = l; i >= 0; --i) {
            if (!IS_ANCESTOR(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    };

    function<void(int, int)> DFS_LCA = [&](int v, int p) -> void {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i <= l; ++i)
            up[v][i] = up[up[v][i-1]][i-1];

        for (int u : adj[v]) {
            if (u != p)
                DFS_LCA(u, v);
        }

        tout[v] = ++timer;
    };

    for(auto i : comp) {
        DFS_LCA(i, i);
    }

    auto FIND_DIST = [&](int x, int y) -> int {
        int z = LCA(x, y);
        return depth[x] + depth[y] - 2*depth[z];
    };

    vector<priority_queue<pair<int, int>>> dist(n);
    for(int i = 0; i < n; i++) {
        dist[i].push({-INF, -2});
        dist[i].push({-INF, -3});
    }

    auto INSERT = [&](int x, pair<int, int> y) -> void {
        dist[x].push(y);
        auto a = dist[x].top();
        dist[x].pop();
        pair <int, int> b;
        while(true) {
            b = dist[x].top();
            if(b.second != a.second) break;
            else dist[x].pop();
        }
        while(!dist[x].empty()) dist[x].pop();
        dist[x].push(a);
        dist[x].push(b);
    };

    auto QUERY = [&](int x, int child) -> int {
        auto a = dist[x].top();
        if(a.second != child) return a.first;
        dist[x].pop();
        int temp = dist[x].top().first;
        dist[x].push(a);
        return temp;
    };

    auto ADD_BARN = [&](int barn) -> void {
        INSERT(barn, {0, barn});
        int nx = p[barn];
        int cr = barn;
        while(nx != -1) {
            INSERT(nx, {FIND_DIST(nx, barn), cr});
            nx = p[nx];
            cr = p[cr];
        }
    };

    auto QUERY_BARN = [&](int barn) -> int {
        int ans = QUERY(barn, -1);
        int nx = p[barn];
        int cr = barn;
        while(nx != -1) {
            ans = max(ans, QUERY(nx, cr) + FIND_DIST(nx, barn));
            nx = p[nx];
            cr = p[cr];
        }
        return max(ans, 0);
    };

    int curr = 0;
    for(auto q : query) {
        if(q.first == 'B') {
            ADD_BARN(curr);
            curr++;
        } else {
            cout << QUERY_BARN(q.second) << '\n';
        }
    }
    
    return 0;
}