#include <bits/stdc++.h>
using namespace std;
// #define int long long

const int SQ = 650;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    map<pair<int, int>, int> edge;
    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        // edge[{min(a, b), max(a, b)}] = c;
        edge[{a, b}] = c;
        edge[{b, a}] = c;
    }
    vector <long long> ans(q);
    map<pair<int, int>, int> query;
    vector<pair<int, int>> repeat;
    for(int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        // query[{x, y}] = i;
        if(query.find({x, y}) == query.end()) {
            query[{x, y}] = i;
        } else {
            repeat.push_back({i, query[{x, y}]});
        }
        // query[{min(x, y), max(x, y)}] = i; 
        // cerr << x + 1 << ' ' << y + 1 << ' ' << i << '\n';
    }
    for(int i = 0; i < n; i++) {
        if((int)adj[i].size() <= SQ) {
            // brute force!
            for(int a = 0; a < (int)adj[i].size(); a++) {
                for(int b = 0; b < (int)adj[i].size(); b++) {
                    pair<int, int> x = {adj[i][a].first, adj[i][b].first};
                    int mn = min(adj[i][a].second, adj[i][b].second);
                    if(query.find(x) != query.end()) {
                        ans[query[x]] += mn;
                    }
                }
            }
        } else {
            for(auto j : query) {
                int a = j.first.first;
                int b = j.first.second;
                // find out if a and b are both conencted to c or not.
                pair<int, int> x = {a, i};
                pair<int, int> y = {i, b};
                if(edge.find(x) != edge.end() && edge.find(y) != edge.end()) {
                    int c = min(edge[x], edge[y]);
                    ans[j.second] += c;
                }
            }
        }
    }
    for(auto j : query) {
        // cerr << j.first.first + 1 << ' ' << j.first.second + 1 << ' ' << edge[j.first] << ' ' << j.second << '\n';
        ans[j.second] += 2 * edge[j.first];
    }
    for(auto i : repeat) {
        ans[i.first] = ans[i.second];
    }
    for(int i = 0; i < q; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    freopen("second_flight_input.txt", "r", stdin);
    freopen("second_flight_output.txt", "w", stdout);
    
    clock_t start = clock();

    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        cout << "Case #" << I << ": ";
        solve();
    }

    clock_t end = clock();

    cerr << "Time taken with SQ = " << SQ << " = " << (double)(end - start)/CLOCKS_PER_SEC;
    
    return 0;
}