// Edmonds-Karp, O(V * E * E)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<vector<long long>> capacity(n, vector<long long>(n, 0));
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        bool exists = false;
        for(auto nx : adj[a]) {
            if(nx == b) exists = true;
        }
        if(!exists) {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        capacity[a][b] += c;
    }

    long long ans = 0;
    while(true) {
        vector <int> parent(n, -1);
        long long flow = 0;
        queue <pair<int, long long>> q;
        q.push({0, (int)1E9 + 7});
        parent[0] = -2;
        while(!q.empty()) {
            int curr = q.front().first;
            long long curr_flow = q.front().second;
            q.pop();
            for(auto next : adj[curr]) {
                if(parent[next] == -1 && capacity[curr][next] > 0) {
                    parent[next] = curr;
                    long long new_flow = min(curr_flow, capacity[curr][next]);
                    if(next == n - 1) {
                        flow = max(flow, new_flow);
                    }
                    q.push({next, new_flow});
                }
            }
        }
        if(flow == 0) break;
        ans += flow;
        int curr = n - 1;
        while(curr != 0) {
            int prev = parent[curr];
            capacity[prev][curr] -= flow;
            capacity[curr][prev] += flow;
            curr = prev;
        }
    }
    cout << ans;

    return 0;
}