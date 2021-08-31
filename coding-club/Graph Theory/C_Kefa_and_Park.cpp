// https://codeforces.com/problemset/problem/580/C

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 100100

int n, m, ans;
vector <int> adj[MAXN];
int hascat[MAXN]; // 0 if no cat, 1 if yes cat.
int dist[MAXN];

void bfs(int start) {
    queue <int> q;
    dist[start] = hascat[start];
    q.push(start);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int e : adj[v]) {
            if(dist[e]==-1) {
                if(hascat[e]) dist[e] = dist[v] + 1;
                else dist[e] = 0;
                if(dist[e]<=m) q.push(e);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t1, t2;
    cin >> n >> m;
    forn(i, n) dist[i] = -1;
    forn(i, n) cin >> hascat[i];
    forn(i, n-1) {
        cin >> t1 >> t2;
        --t1;
        --t2;
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
    }
    ans = 0;
    bfs(0);
    for(int i=1; i<n; i++) {
        if((adj[i].size()==1)&&(dist[i]>=0)&&(dist[i]<=m)) {
            ans += 1;
        }
    }
    cout << ans;
    return 0;
}
