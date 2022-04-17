#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

vector <int> d;

struct Comp {
    bool operator()(int a, int b) {
        return d[a] < d[b];
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    d.resize(n, 0);
    for(int i = 0; i < n; i++) {
        d[i] = adj[i].size();
    }
    vector <int> c(n, -1);
    vector <bool> pushed(n, false);
    priority_queue<int, vector<int>, Comp> q;
    for(int i = 0; i < n; i++) {
        if((int)adj[i].size() == 1) {
            pushed[i] = true;
            c[i] = 0;
            pushed[adj[i][0]] = true;
            c[adj[i][0]] = 1;
            for(auto next : adj[adj[i][0]]) {
                if(pushed[next] == false) {
                    pushed[next] = true;
                    q.push(next);
                }
            }
        }
    }
    while(!q.empty()) {
        int curr = q.top();
        q.pop();
        cout << curr << " " << d[curr] << endl;
    }
    
    return 0;
}