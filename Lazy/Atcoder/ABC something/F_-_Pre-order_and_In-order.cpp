#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector <int> p, q;
bool pos = true;
vector<vector<int>> adj;
vector<int> parent;
vector<pair<int, int>> r; // range

void dfs(int node, int ind) {
    if(ind == n) return;
    int curr = p[ind];
    if(r[node].first < q[curr] && q[curr] < r[node].second) {
        if(q[node] > q[curr]) {
            // Next value should be to the left.
            if(adj[node][0] != -1) {
                pos = false;
                return;
            }
            adj[node][0] = curr;
            r[curr] = {r[node].first, min(r[node].second, q[node])};
            parent[curr] = node;
            dfs(curr, ind + 1);
        } else {
            // Next value should be to the right.
            if(adj[node][1] != -1) {
                pos = false;
                return;
            }
            parent[curr] = node;
            adj[node][1] = curr;
            r[curr] = {max(r[node].first, q[node]), r[node].second};
            dfs(curr, ind + 1);
        }
    } else {
        // Go Up.
        if(node == 0) {
            pos = false;
            return;
        }
        dfs(parent[node], ind);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    p.resize(n); q.resize(n);
    adj.resize(n, vector<int>(2, -1));
    parent.resize(n, -1);
    r.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        --p[i];
    }
    for(int i = 0; i < n; i++) {
        int x; cin >> x; --x;
        q[x] = i;
    }
    if(p[0] != 0) {
        cout << -1;
        return 0;
    }
    r[0] = {-1, n};
    dfs(0, 1);
    if(!pos) {
        cout << -1;
        return 0;
    }
    for(int i = 0; i < n; i++) {
        cout << adj[i][0] + 1 << " " << adj[i][1] + 1 << '\n';
    }
    
    return 0;
}