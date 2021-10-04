#include <bits/stdc++.h>
using namespace std;

#define int long long
// #define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 1010;
const int MOD = 1000000007;

int n;
vector<pair<int, int>> edge;
vector<int> adj[MAXN];
int ans;
int stt;

bool check(int l, int r) {
    cout << "? ";
    set <int> s;
    forn(i, l, r + 1) {
        s.insert(edge[i-1].first);
        s.insert(edge[i-1].second);
    }
    cout << s.size() << " ";
    for(auto i : s) cout << i << " ";
    cout << endl;
    int x; cin >> x;
    if(x==ans) return true;
    return false;
}

void bfs(int start) {
    int dist[MAXN];
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto next : adj[curr]) {
            if(dist[next] == -1) {
                edge.push_back({next + 1, curr + 1});
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
}

void solve() {
    cin >> n;
    forn(i, 0, n - 1) {
        int t1, t2;
        cin >> t1 >> t2;
        --t1; --t2;
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
    }
    forn(i, 0, n) if(adj[i].size()==1) stt = i;
    bfs(stt);
    cout << "? " << n << " ";
    forn(i, 1, n + 1) cout << i << " ";
    cout << endl;
    cin >> ans;
    vector <int> v;
    int m = n - 1;
    while(m > 1) {
        if(m%2) m = m/2 + 1;
        else m = m/2;
        v.push_back(m);
    }
    // for(auto i : v) cout << i << " ";
    // v --> The gap at each stage.
    int left = 1;
    forn(i, 0, v.size()) {
        // Check from left to left + v[i] - 1.
        // If it is false, left += v[i].
        // True --> No change.
        if(!check(left, left + v[i] - 1)) {
            left += v[i];
        }
    }
    cout << "! " << edge[left-1].first << " " << edge[left-1].second;
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