#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

const int MAXN = 200100;

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
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n);
    vector <int> v(n); // stores values of nodes
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    } 
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector <int> tin(n, -1), tout(n, -1);
    vector <int> a; // stores the DFS traversal of the tree
    int timer = 0;
    auto DFS = y_combinator([&](auto self, int node, int prev) -> void {
        tin[node] = timer++;
        a.push_back(node);
        for(auto next : adj[node]) {
            if(next != prev) {
                self(next, node);
            }
        }
        tout[node] = timer;
    });
    DFS(0, 0);

    // for(auto i : a) cout << i + 1 << " "; cout << endl;
    // for(int i = 0; i < n; i++) {
    //     cout << tin[i] << " " << tout[i] << endl;
    // }

    // For node X, the query should be from tin[node] to tout[node] - 1.
    vector<vector<int>> pos(MAXN + 5);
    for(int i = 0; i < n; i++) {
        pos[v[a[i]]].push_back(i);
        // cout << i << " " << v[i] << endl;
    }

    vector<vector<int>> query(q, vector<int>(3));
    vector<int> isq(MAXN + 5, 0);
    for(int i = 0; i < q; i++) {
        cin >> query[i][0] >> query[i][1] >> query[i][2];
        isq[query[i][2]] = 1;
    }

    vector<vector<int>> mul(MAXN + 5);
    for(int i = 1; i <= MAXN; i++) {
        for(int j = i; j <= MAXN; j += i) {
            if(!isq[j]) continue;
            // for(auto k : pos[j]) {
            //     mul[i].push_back(k);
            // }
            for(auto k : pos[i]) {
                mul[j].push_back(k);
            }
        }
    }
    for(int i = 1; i <= MAXN; i++) {
        sort(mul[i].begin(), mul[i].end());
    }

    // for(int i = 0; i < 10; i++) {
    //     cout << i << ": ";
    //     for(auto j : mul[i]) cout << j << " ";
    //     cout << endl;
    // }


    auto QUERY = y_combinator([&](auto self, int i, int j, int x) -> int {
        // return number of values from i to j that are multiples of x.
        int t1 = upper_bound(mul[x].begin(), mul[x].end(), j) - mul[x].begin();
        int t2 = lower_bound(mul[x].begin(), mul[x].end(), i) - mul[x].begin() - 1;
        return t1 - t2;
    });
    for(int i = 0; i < q; i++) {
        int u, v, x;
        u = query[i][0] - 1;
        v = query[i][1] - 1;
        x = query[i][2];
        // cin >> u >> v >> x;
        int a = QUERY(tin[u], tout[u] - 1, x);
        int b = QUERY(tin[v], tout[v] - 1, x);
        // cout << a << " " << b << " ";
        if(a == b) cout << "Draw" << endl;
        else if(a > b) cout << u + 1 << endl;
        else cout << v + 1 << endl;
    }

    return 0;
}