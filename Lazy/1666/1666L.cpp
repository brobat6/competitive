#include <bits/stdc++.h>
using namespace std;
#define int long long

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    int s; cin >> s; --s;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int t;
    bool found = false;
    vector <int> vis(n, -1);
    auto DFS = y_combinator([&](auto dfs, int node, int prev) -> void {
        vis[node] = prev;
        for(auto next : adj[node]) {
            if(found) continue;
            if(next == prev) continue;
            if(next == s) {
                found = true;
                t = node;
                continue;
            }
            if(vis[next] >= 0) continue;
            dfs(next, node);
        }
    });
    DFS(s, s);
    cout << (found ? "Possible" : "Impossible") << '\n';
    if(!found) return 0;
    cout << 2 << '\n' << s + 1 << " " << t + 1 << '\n';
    vector <int> store;
    int curr = t;
    while(curr != s) {
        store.push_back(curr);
        curr = vis[curr];
    }
    store.push_back(s);
    reverse(store.begin(), store.end());
    cout << (int)store.size() << '\n';
    for(auto i : store) cout << i + 1 << " ";
    
    return 0;
}