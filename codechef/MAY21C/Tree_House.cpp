//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 300100
#define MOD 1000000007

long long n, x;
vector <long long> adj[MAXN];
long long dist[MAXN];
long long arr[MAXN];

struct Depth {
    long long id;
    long long depth;
};

Depth dc[MAXN];

bool comp(Depth a, Depth b) {
    return a.depth > b.depth;
}

void bfs(long long start) {
    queue<long long> q;
    dist[start] = 0;
    q.push(start);
    while(!q.empty()) {
        long long v = q.front();
        q.pop();
        for(long long e: adj[v]) {
            if(dist[e] == -1) {
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
    long long t;
    cin >> t;
while(t--) {
    cin >> n >> x;
    forn(i, n) {
        dist[i] = -1;
        arr[i] = 0;
        adj[i].clear();
    }
    forn(i, n-1) {
        long long a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(0);
    forn(i, n) {
        dc[i].id = i;
        dc[i].depth = dist[i];
    }
    sort(dc, dc+n, comp);
    forn(i, n) {
        long long c = dc[i].id;
        if((adj[c].size()==1)&&(c!=0)) {
            arr[c] = 1;
        }
        else {
            vector <long long> temp;
            long long sot = 0;
            for(auto it: adj[c]) {
                if(dist[it] > dist[c]) {
                    temp.push_back(arr[it]);
                    sot++;
                }
            }
            sort(temp.begin(), temp.end());
            for(auto it: temp) {
                arr[c] += (it * sot);
                sot--;
            }
            arr[c] += 1;
        }
    }
    long long ans = arr[0] % MOD;
    ans *= x;
    ans %= MOD;
    cout << ans << endl;
}
    return 0;
}