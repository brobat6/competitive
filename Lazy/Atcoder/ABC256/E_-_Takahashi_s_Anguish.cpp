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
    
    int n;
    cin >> n;
    vector <int> nx(n);
    vector <bool> source(n, true);
    for(int i = 0; i < n; i++) {
        cin >> nx[i];
        nx[i]--;
        source[nx[i]] = false;
    }
    vector <int> f(n);
    for(int i = 0; i < n; i++) {
        cin >> f[i];
    }
    vector <int> vis(n, 0);
    vector <int> cycle;
    auto DFS = y_combinator([&](auto self, int node) -> void {
        vis[node] = 1;
        int next = nx[node];
        if(vis[next] == 1) {
            cycle.push_back(node);
        } else if(vis[next] == 0) {
            self(next);
        }
        vis[node] = 2;
    });
    for(int i = 0; i < n; i++) {
        if(source[i]) {
            DFS(i);
        }
    }
    for(int i = 0; i < n; i++) {
        if(vis[i] == 0) {
            DFS(i);
        }
    }
    int ans = 0;
    for(auto i : cycle) {
        int temp = f[i];
        int j = nx[i];
        while(j != i) {
            temp = min(temp, f[j]);
            j = nx[j];
        }
        ans += temp;
    }
    cout << ans;
    
    return 0;
}