#include <bits/stdc++.h>
using namespace std;
#define MAXN 20

int n, m;
vector <int> adj[MAXN];
int dist[MAXN];
int pre[MAXN]; // To store the previous node found using BFS. Useful when we need all vertices of shortest path.

void bfs(int start) {
    memset(dist, -1, sizeof(dist));
    memset(pre, -1, sizeof(pre));
    queue<int> q;
    dist[start] = 0;
    pre[start] = -1;
    q.push(start);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto next : adj[curr]) {
            if(dist[next]==-1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
                pre[next] = curr;
            }
        } 
    }
}

vector<int> path;

void shortest_path(int target) {
    if(dist[target]==-1) {
        cout << "No path!";
        return;
    }
    for(int v = target; v != -1; v = pre[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
}