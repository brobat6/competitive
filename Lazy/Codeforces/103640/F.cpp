// g++ A.cpp
// ./a < input.txt > output.txt

#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector <int> vis(n, false);

    function<void(int)> DFS = [&](int node) -> void {
        vis[node] = true;
        for(auto next : adj[node]) {
            if(next != n - 1 && !vis[next]) {
                DFS(next);
            }
        }
    };

    DFS(n - 2);

    for(auto i : vis) {
        cout << (i ? 'B' : 'A');
    }
	
	return 0;
}