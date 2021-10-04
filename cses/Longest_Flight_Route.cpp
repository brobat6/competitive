#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 100100;
const int MOD = 1000000007;

int n, m, t1, t2;
vector <int> adj[MAXN];
vector <int> bac[MAXN];
pair<int, int> dist[MAXN];

// Max possible answer ?

void bfs() {
    queue<int> q;
    forn(i, 0, n) dist[i] = {-1, 0};
    q.push(0);
    dist[0] = {0, 0};
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto next : adj[curr]) {
            if(dist[next].first == -1) {
                dist[next].first = dist[curr].first + 1;
                q.push(next);
            }
            else {
                dist[next].second = max(dist[next].second, dist[curr].first + 1);
            }
        }
    }
}



void solve() {
    cin >> n >> m;
    forn(i, 0, m) {
        cin >> t1 >> t2;
        adj[--t1].push_back(--t2);
        bac[t2].push_back(t1);
    }
    bfs();
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}