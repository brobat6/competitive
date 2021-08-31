// https://codeforces.com/group/ajZVdc9MCh/contest/320153/problem/0

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 200

int n,l;
vector <int> adj[MAXN];

bool check(int start) {
    int dist[MAXN];
    int color[MAXN];
    forn(i, MAXN) color[i] = -1;
    forn(i, MAXN) dist[i] = -1;
    dist[start] = 0;
    color[start] = 1;
    queue <int> q;
    q.push(start);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int e : adj[v]) {
            if(dist[e]==-1) {
                dist[e] = dist[v] + 1;
                q.push(e);
                if(dist[e]%2==1) {
                    color[e] = 2;
                }
                else {
                    color[e] = 1;
                }
            }
            if(color[e]==color[v]) return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> l;
        forn(i, MAXN) adj[i].clear();
        int a, b;
        forn(i, l) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int ans = 1;
        forn(i, MAXN) {
            if(adj[i].size()==0) continue;
            if(!check(i)) {
                ans = 0;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
