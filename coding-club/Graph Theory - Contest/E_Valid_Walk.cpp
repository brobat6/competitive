//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 5000

int n, m;
vector <pair<int,int>> adj[MAXN];
bool visited[MAXN];
int dist[MAXN];
vector <int> origin;

void bfs(int start) {
    origin.clear();
    memset(dist, -1, sizeof dist);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(auto e : adj[v]) {
            if(dist[e.first]==0) {
                origin.push_back(dist[v]+e.second);
            }
            if(dist[e.first]==-1) {
                dist[e.first] = dist[v] + e.second;
                q.push(e.first);
            }
            else {
                dist[e.first] = min(dist[e.first], dist[v] + e.second);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int x,y,z;
    cin >> n >> m;
    forn(i, m) {
        cin >> x >> y >> z;
        --x; --y;
        adj[x].push_back({y,z});
    }
    forn(i, n) {
        bfs(i);
        if(origin.size()==0) cout << -1 << endl;
        else {
            sort(origin.begin(), origin.end());
            cout << origin[0] << endl;
        }
    }

    return 0;
}
