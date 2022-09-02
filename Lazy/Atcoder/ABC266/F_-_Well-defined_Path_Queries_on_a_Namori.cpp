#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;

class DetectCycle {
public:
    vector <int> p;
    int last;
    int first;
    vector <int> vis;
    vector <int> cycle;

    void dfs(int node, int prev) {
        p[node] = prev;
        vis[node] = true;
        if(last != -1) return;
        for(auto next : adj[node]) {
            if(next == prev) continue;
            if(vis[next]) {
                // found cycle!
                last = node;
                first = next;
                return;
            }
            dfs(next, node);
            if(last != -1) return;
        }
    }

    DetectCycle() {
        p.resize(n, -1);
        vis.resize(n, false);
        last = -1;
        first = -1;
        dfs(0, 0);
        cycle.push_back(last);
        int curr = p[last];
        while(curr != first) {
            cycle.push_back(curr);
            curr = p[curr];
        }
        cycle.push_back(first);
    }
};

vector <bool> cycle;
vector <int> root;

void dfs(int node, int prev, int tree_root) {
    root[node] = tree_root;
    for(auto next : adj[node]) {
        if(next != prev && cycle[next] == false) {
            dfs(next, node, tree_root);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    adj.resize(n);
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    DetectCycle dc;
    auto roots = dc.cycle;
    // for(auto i : roots) cout << i + 1 << ' ';
    cycle.resize(n, false);
    root.resize(n, -1);
    for(auto i : roots) {
        cycle[i] = true;
    }
    for(int i = 0; i < n; i++) {
        if(cycle[i]) {
            dfs(i, i, i);
        }
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        if(cycle[x] && cycle[y]) {
            cout << "No" << '\n';
        } else {
            if(root[x] == root[y]) cout << "Yes" << '\n';
            else cout << "No" << '\n';
        }
    }
    
    return 0;
}