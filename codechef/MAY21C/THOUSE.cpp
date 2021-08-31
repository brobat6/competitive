//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 300100
#define MOD 1000000007

long long n, x;
vector <long long> adj[MAXN];
bool visited[MAXN];
long long val[MAXN];
long long depth[MAXN];
long long ich[MAXN]; // Number of immediate children
long long ch[MAXN]; // Number of total children

struct Depth {
    long long x;
    long long y;
};

Depth dc[MAXN];

bool comp(Depth a, Depth b) {
    return a.y > b.y;
}

bool comp_rev(Depth a, Depth b) {
    return a.y < b.y;
}

struct Final {
    long long x;
    long long y;
    long long z;
};

bool cmp(Final a, Final b) {
    if(a.y==b.y) return a.z > b.z;
    return a.y > b.y;   
}

void bfs(long long start) {
    queue <long long> q;
    depth[start] = 0;
    q.push(start);
    while(!q.empty()) {
        long long v = q.front();
        q.pop();
        for(long long e: adj[v]) {
            if(depth[e] == -1) {
                depth[e] = depth[v] + 1;
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
    long long t;
    cin >> t;
while(t--) {
    cin >> n >> x;
    forn(i, n) {
        adj[i].clear();
        visited[i] = false;
        val[i] = 0;
        depth[i] = -1;
        ich[i] = 0;
        ch[i] = 0;
    }
    val[0] = x;
    forn(i, n-1) {
        long long a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        ich[a]++;
        ich[b]++;
    }
    forn(i, n-1) ich[i+1]--;
    bfs(0);
    forn(i, n) {
        dc[i].x = i;
        dc[i].y = depth[i];
    }
    sort(dc, dc+n, comp);
    forn(i, n) {
        for(long long node: adj[dc[i].x]) {
            if(depth[node] > depth[dc[i].x]) {
                ch[dc[i].x] += 1;
                ch[dc[i].x] += ch[node];
            }
        }
    }
    sort(dc, dc+n, comp_rev);
    forn(i, n) {
        long long it = 0;
        Final f[adj[dc[i].x].size() + 1];
        for(long long node: adj[dc[i].x]) {
            if(depth[node] > depth[dc[i].x]) {
                f[it].x = node;
                f[it].y = ch[node];
                f[it].z = ich[node];
                it++;
            }
        }
        sort(f, f+it, cmp);
        long long itt = it;
        it = 1;
        forn(j, itt) {
            val[f[j].x] = it*val[dc[i].x];
            it++; 
        } 
    }
    long long ans = 0;
    forn(i, n) {
        ans += val[i];
        ans %= MOD;
    }
    cout << ans << endl;
}
    return 0;
}
