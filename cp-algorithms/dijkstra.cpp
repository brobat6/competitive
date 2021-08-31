#include<bits/stdc++.h>
#define MAXN 100100
#define INF 1000000000
using namespace std;

int n, m; // n vertices, m edges
vector <pair<int, int>> adj[MAXN];
priority_queue <pair<int, int>> q;
int dist[MAXN];
bool visited[MAXN];

void dijkstra(int x) {
    dist[x] = 0;
    q.push({0, x});
    while(!q.empty()) {
        int a = q.top().second; q.pop();
        if(visited[a]) continue;
        visited[a] = true;
        for(auto u: adj[a]) {
            int b = u.first, w = u.second;
            if(dist[a]+w < dist[b]) {
                dist[b] = dist[a] + w;
                q.push({-dist[b], b});
            }
        }
    }
}

int main() {
    // Input - 
    // 5 6
    // 1 2 5
    // 2 3 2
    // 3 4 6
    // 4 5 2
    // 5 1 1
    // 4 1 9
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    dijkstra(1);
    for(int i=1; i<=n; i++) {
        printf("The minimum distance to node %d is %d.\n", i, dist[i]);
    }
}