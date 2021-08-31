//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 100100

int n;
vector <int> adj[MAXN];
int init[MAXN], goal[MAXN], dist[MAXN], flip[MAXN];

void bfs(int start) {
    queue <int> q;
    dist[start] = 0;
    q.push(start);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int e : adj[v]) {
            if(dist[e]==-1) {
                dist[e] = dist[v] + 1;
                q.push(e);
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
    cin >> n;
    forn(i, n) dist[i] = -1;
    forn(i, n-1) {
        cin >> t1 >> t2;
        --t1; --t2;
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
    }
    forn(i, n) cin >> init[i];
    forn(i, n) cin >> goal[i];
    return 0;
}
