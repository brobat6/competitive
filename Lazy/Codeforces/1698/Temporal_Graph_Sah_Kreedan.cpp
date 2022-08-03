#include <bits/stdc++.h>
using namespace std;
#define int long long

const int X = 51;

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
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> house(n, vector<int>(X, 0));
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            for(int j = 0; j < x; j++) {
                int x, y;
                cin >> x >> y;
                for(int k = x; k <= y; k++) {
                    house[i][k] = 1;
                }
            }
        }
        int m;
        cin >> m;
        vector<vector<int>> portal(m, vector<int>(X, 0));
        vector<pair<int, int>> edge(m);
        for(int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            edge[i] = {x, y};
            int z;
            cin >> z;
            for(int j = 0; j < z; j++) {
                cin >> x >> y;
                for(int k = x; k <= y; k++) {
                    portal[i][k] = 1;
                }
            }
        }
        int start, end;
        cin >> start >> end;
        --start;
        --end;
        int ans = 0;
        for(int t = 0; t < X; t++) {
            vector <int> pos(n, false);
            for(int i = 0; i < n; i++) {
                if(house[i][t]) {
                    pos[i] = true;
                }
            }
            if(pos[start] == false || pos[end] == false) continue;
            vector <vector<int>> adj(n);
            for(int i = 0; i < m; i++) {
                if(portal[i][t]) {
                    int f = edge[i].first;
                    int s = edge[i].second;
                    if(pos[f] && pos[s]) {
                        adj[f].push_back(s);
                        adj[s].push_back(f);
                    }
                }
            }
            vector <int> vis(n, false);
            auto DFS = y_combinator([&](auto self, int node) -> void {
                vis[node] = true;
                for(auto next : adj[node]) {
                    if(!vis[next]) {
                        self(next);
                    }
                }
            });
            DFS(start);
            if(vis[end]) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}