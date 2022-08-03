#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> adj;
vector <int> subtree_size;
int n;

int get_subtree_size(int node, int par = -1) {
	int& res = subtree_size[node];
	res = 1;
	for (int i : adj[node]) {
		if (i == par) continue;
		res += get_subtree_size(i, node);
	}
	return res;
}

int get_centroid(int node, int par = -1) {
	for (int i : adj[node]) {
		if (i == par) continue;

		if (subtree_size[i] * 2 > n) {
			return get_centroid(i, node);
		}
	}
	return node;
}

vector <int> dp;

int dfs(int node, int prev) {
    int ans = 0;
    for(auto next : adj[node]) {
        if(next == prev) continue;
        ans += dfs(next, node) + 1;
    }
    dp[node] = ans;
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        adj.clear();
        adj.resize(n);
        subtree_size.clear();
        subtree_size.resize(n);
        dp.resize(n);
        for(int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector <int> ans(n, 0);
        if(n % 2 == 1) {
            for(auto i : ans) cout << i;
            cout << '\n';
            continue;
        }
        get_subtree_size(0);
        int root = get_centroid(0);
        // queue <int> q;
        // vector <int> d(n, -1);
        // for(int i = 0; i < n; i++) {
        //     if((int)adj[i].size() == 1) {
        //         q.push(i);
        //         d[i] = 0;
        //     }
        // }
        // while(!q.empty()) {
        //     int curr = q.front();
        //     q.pop();
        //     for(auto next : adj[curr]) {
        //         if(d[next] == -1) {
        //             d[next] = d[curr] + 1;
        //             q.push(curr);
        //         }
        //     }
        // }
        dfs(root, root);
        for(int i = 0; i < n; i++) {
            if(dp[i] >= (n - 1)/2) ans[i] = 1;
        }
        for(auto i : ans) cout << i;
        cout << '\n';
    }
    
    return 0;
}