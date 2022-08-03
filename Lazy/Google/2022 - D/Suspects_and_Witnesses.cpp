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

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[b].push_back(a);
    }
    vector <int> vis(n, false);
    int ans = 0;
    vector <int> temp;
    int found;
    auto DFS = y_combinator([&](auto self, int node) -> void {
        temp.push_back(node);
        vis[node] = true;
        found++;
        for(auto next : g[node]) {
            if(!vis[next]) {
                if(found >= k) return;
                self(next);
            }
        }
    });
    for(int start = 0; start < n; start++) {
        temp.clear();
        found = -1;
        DFS(start);
        if(found >= k) ans++;
        for(auto i : temp) {
            vis[i] = false;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        cout << "Case #" << I << ": ";
        solve();
    }
    
    return 0;
}