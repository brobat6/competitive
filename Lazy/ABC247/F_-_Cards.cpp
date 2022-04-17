#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 998244353;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<int> adj(n);
    for(int i = 0; i < n; i++) {
        adj[a[i] - 1] = b[i] - 1;
    }
    vector <int> cycle;
    vector <bool> vis(n, false);
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            int start = i;
            vis[start] = true;
            int curr = adj[i];
            vis[curr] = true;
            int cnt = 1;
            while(curr != start) {
                cnt++;
                curr = adj[curr];
                vis[curr] = true;
            }
            cycle.push_back(cnt);
        }
    }
    int ans = 1;

    vector <int> fib(n + 5);
    
    fib[0] = 1;
    fib[1] = 3;
    for(int i = 2; i < n; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }

    for(auto c : cycle) {
        ans = (ans * fib[c - 1]) % MOD;
    }
    cout << ans;

    return 0;
}