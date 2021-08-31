//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 3015
#define MOD 1000000007

long long n, a, b;
vector <long long> adj[MAXN];
long long dist[MAXN];
long long arr[MAXN];
long long dp[MAXN];

void bfs(long long start) {
    queue <long long> q;
    dist[start] = -1;
    q.push(start);
    while(!q.empty()) {
        long long v = q.front();
        q.pop();
        for(long long e: adj[v]) {
            if(dist[e]==-2) {
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
    dp[0] = 1;
    forn(i, MAXN-1) {
        dp[i+1] = dp[i] * 2;
        dp[i+1] %= MOD;
    }
    long long t; cin >> t;
while(t--) {
    cin >> n;
    forn(i, n) {
        adj[i].clear();
        arr[i] = 0;
    }
    forn(i, n-1) {
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    forn(i, n) {
        forn(j, n) dist[j] = -2;
        bfs(i);
        forn(j, n) {
            if(dist[j]<0) continue;
            arr[dist[j]] += 1;
        }
    }
    forn(i, n) arr[i] /= 2;
    long long ans = n;
    forn(i, n) {
        ans += (arr[i]*dp[i]);
        ans %= MOD;
    }
    cout << ans << endl;
}
    return 0;
}