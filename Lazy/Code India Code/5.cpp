#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int MAXN = 100100;

vector <int> adj[MAXN];
vector <int> num;
int n, a, b;
int dista[MAXN];
int distb[MAXN];
vector <int> m; // stores max gcd in case of DFS
int ans, ans2, ans3;

void dfs(int node, int prev) {
    if(num[node] == 0) m[node] = m[prev];
    else m[node] = __gcd(num[node], m[prev]);
    if((int)adj[node].size() == 1 && node != prev) {
        ans = max(ans, m[node]);
    }
    for(auto next : adj[node]) {
        if(next == prev) continue;
        dfs(next, node);
    }
}

void dfs2(int node, int prev) {
    if(num[node] == 0) m[node] = m[prev];
    else m[node] = __gcd(num[node], m[prev]);
    if((int)adj[node].size() == 1 && node != prev) {
        ans2 = max(ans2, m[node]);
    }
    for(auto next : adj[node]) {
        if(next == prev) continue;
        dfs2(next, node);
    }
}

void dfs3(int node, int prev) {
    if(num[node] == 0) m[node] = m[prev];
    else m[node] = __gcd(num[node], m[prev]);
    if((int)adj[node].size() == 1 && node != prev) {
        ans3 = max(ans3, m[node]);
    }
    for(auto next : adj[node]) {
        if(next == prev) continue;
        dfs3(next, node);
    }
}

void bfs_a(int start) {
    for(int i = 0; i < n; i++) {
        dista[i] = -1;
    }
    queue <int> q;
    dista[start] = 0;
    q.push(start);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto next : adj[curr]) {
            if(dista[next] == -1) {
                dista[next] = dista[curr] + 1;
                q.push(next);
            }
        }
    }
}

void bfs_b(int start) {
    for(int i = 0; i < n; i++) {
        distb[i] = -1;
    }
    queue <int> q;
    distb[start] = 0;
    q.push(start);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto next : adj[curr]) {
            if(distb[next] == -1) {
                distb[next] = distb[curr] + 1;
                q.push(next);
            }
        }
    }
}

void pre() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        adj[i].clear();
    }
    m.resize(n);
    num.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for(int i = 0; i < n - 1; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        --t1; --t2;
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
    }
    cin >> a >> b;
    --a; --b;
    bfs_a(a);
    bfs_b(b);
    num[b] = 0;
}

void solve() {
    pre();
    // Two cases. First --> Geekina goes down until there is a branch
    int node = b;
    map <int, int> change;
    while(true) {
        change[node] = num[node];
        num[node] = 0;
        int cnt = 0;
        int child = -1;
        for(auto next : adj[node]) {
            if(dista[next] > dista[node]) {
                cnt++;
                child = next;
            }
        }
        if(cnt == 1) {
            node = child;
        } else {
            break;
        }
    }
    for(int i = 0; i < n; i++) {
        m[i] = num[i];
    }
    ans = -1E18;
    dfs(a, a);
    // Second case.
    for(auto i : change) {
        num[i.first] = i.second;
    }
    node = b;
    int prev = b;
    int big_child = -1;
    map <int, int> big_change;
    while(true) {
        if(dista[node] <= distb[node]) {
            break;
        }
        big_change[node] = num[node];
        num[node] = 0;
        int cnt = 0;
        int parent = -1;
        int child = -1;
        for(auto next : adj[node]) {
            if(dista[next] > dista[node]) {
                cnt++;
                if(next != prev) child = next;
            } else {
                parent = next;
            }
        }
        if(node == b && cnt > 1) break;
        if(cnt > 2) break;
        if(cnt == 2) {
            // Special case????
            // Two cases.
            // 1 --> go to child
            // 2 --> go to parent!!
            if(big_child == -1) {
                big_child = node;
            }
            else {
                break;
            }
        }
        node = parent;
    }
    ans2 = -1E18;
    for(int i = 0; i < n; i++) {
        m[i] = num[i];
    }
    dfs2(a, a);
    for(auto i : big_change) {
        num[i.first] = i.second;
    }
    node = b;
    ans3 = -1E18;
    if(big_child != -1) {
        while(true) {
            num[node] = 0;
            if(node == big_child) {
                int child = -1;
                for(auto next : adj[node]) {
                    if(dista[next] > dista[node]) {
                        if(num[next] != 0) {
                            node = next;
                        }
                    }
                }
                break;
            }
            int parent = -1;
            for(auto next : adj[node]) {
                if(dista[next] < dista[node]) {
                    parent = next;
                }
            }
            node = parent;
        }
        while(true) {
            num[node] = 0;
            int cnt = 0;
            int child = -1;
            for(auto next : adj[node]) {
                if(dista[next] > dista[node]) {
                    cnt++;
                    child = next;
                }
            }
            if(cnt == 1) {
                node = child;
            } else {
                break;
            }
        }
        
        for(int i = 0; i < n; i++) {
            m[i] = num[i];
        }
        dfs3(a, a);
    }
    vector <int> v;
    if(ans != -1E18) v.push_back(ans);
    if(ans2 != -1E18)v.push_back(ans2);
    if(ans3 != -1E18)v.push_back(ans3);
    sort(v.begin(), v.end());
    if(v.size() == 1) cout << v[0] << endl;
    else if(v.size() == 2) cout << v[0] << endl;
    else cout << v[1] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}