#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 300100;
const int MOD = 1000000007;

int n, k, root;
vector <int> dist, p;
vector <vector<int>> adj;
vector <pair<int, int>> xy;

void bfs_dist(int start) {
    queue <int> q;
    dist[start] = 0;
    q.push(start);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto next : adj[curr]) {
            if(dist[next]==-1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
}

bool comp(pair<int, int> a, pair<int, int> b) {
	if(dist[a.first]==dist[b.first]) return dist[a.second] < dist[b.second];
	return dist[a.first] < dist[b.first];
    // if(dist[a.second]==dist[b.second]) return dist[a.first] < dist[b.first];
    // return dist[a.second] < dist[b.second];
}

vector <int> start, endd;
vector <int> order;
vector <bool> done;

bool bfs(int root) {
    queue <int> q, t;
    done[root] = true;
    q.push(root);

    for(auto i : xy) {
        if(endd[i.first]==i.first) t.push(i.first);
    }
    
    while(!q.empty() || !t.empty()) {
        if(q.empty()) {
            int x = t.front();
            t.pop();
            if(done[x]) continue;
            while(start[x] != x) {
                if(done[p[x]]) {
                    q.push(x);
                    order.push_back(x);
                    done[x] = true;
                    x = start[x];
                }
                else return false;
            }
            if(done[p[x]]) {
                    q.push(x);
                    order.push_back(x);
                    done[x] = true;
                }
                else return false;
            }
        else {
            int curr = q.front();
            q.pop();
            for(auto next : adj[curr]) {
                if(dist[next] > dist[curr] && start[next]==next && endd[next]==next && done[p[next]]) {
                    q.push(next);
                    order.push_back(next);
                    done[next] = true;
                    // cerr << next << " pushed to queue!\n";
                }
            }
        }
    }
    return true;
}

void solve() {
    cin >> n >> k;
    n += 1;
    adj.resize(n); dist.resize(n, -1); p.resize(n);
    done.resize(n); xy.resize(k); 
    start.resize(n); endd.resize(n); done.resize(n);
    start[0] = endd[0] = 0;
    forn(i, 1, n) {
        done[i] = false;
        start[i] = endd[i] = i;
        cin >> p[i];
        adj[p[i]].push_back(i);
    }
    bfs_dist(0);
    // for(auto i : dist) cout << i << " ";
    forn(i, 0, k) {
        cin >> xy[i].first >> xy[i].second;
        start[xy[i].first] = xy[i].second;
        endd[xy[i].second] = xy[i].first;
    }
    forn(i, 1, n) {
        if(endd[i]==i) continue;
        if(i == endd[endd[i]]) {
            cout << 0;
            return;
        }
    }
    sort(xy.begin(), xy.end(), comp);
    // for(auto i : xy) cout << i.first << " " << i.second << endl;
    if(bfs(0)) {
        for(auto i : order) cout << i << " ";
    }
    else cout << 0;
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