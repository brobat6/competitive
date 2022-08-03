#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = (int)1E18;

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
        vector <int> a(n), b(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        vector<vector<int>> adj(n);
        for(int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<vector<int>> dp(n, vector<int>(3, -1));
        auto DFS = y_combinator([&](auto self, int node, int prev, int color) -> int {

            if(dp[node][color + 1] >= 0) return dp[node][color + 1];

            int p1 = 1; // assuming I paint.
            int p2 = 0; // assuming I don't paint
            for(auto next : adj[node]) {
                if(next == prev) continue;
                if(color == -1) {
                    if(a[node] == b[node]) {
                        // I could both paint and not paint.
                        p1 += self(next, node, b[node]);
                        p2 += self(next, node, -1);
                    } else {
                        // I have to paint.
                        p1 += self(next, node, b[node]);
                    }
                } else {
                    if(color == b[node]) {
                        // I could both paint and not paint.
                        p1 += self(next, node, b[node]);
                        p2 += self(next, node, color);
                    } else {
                        // I have to paint.
                        p1 += self(next, node, b[node]);
                    }
                }
            }
            int ans;
            if(color == -1) {
                if(a[node] == b[node]) ans = min(p1, p2);
                else ans = p1;
            } else {
                if(color == b[node]) ans = min(p1, p2);
                else ans = p1;
            }
            dp[node][color + 1] = ans;
            return ans;
        });
        cout << DFS(0, 0, -1) << '\n';
    }
    
    return 0;
}