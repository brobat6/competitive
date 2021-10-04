#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

int n, k, t1;
vector <int> f[MAXN], b[MAXN];
int sz[MAXN], pre[MAXN], ans[MAXN];

bool comp(int a, int b) {
    if(ans[a]==ans[b]) return a < b;
    return ans[a] < ans[b]; 
}

void bfs(vector <int> &start) {
    queue <int> q;
    for(auto i : start) {
        q.push(i);
        ans[i] = 1;
    }
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto next : f[curr]) {
            pre[next]++;
            if(sz[next] == pre[next]) {
                // This means we can now READ next.
                sort(b[next].begin(), b[next].end(), comp);
                int c = b[next][0];
                if(c > next) ans[next] = ans[c] + 1;
                else ans[next] = ans[c];
                q.push(next);
            }
        }
    }
}

void solve() {
    cin >> n;
    forn(i, 0, n) {
        f[i].clear();
        b[i].clear();
        sz[i] = 0;
        pre[i] = 0;
        ans[i] = -1;
    }
    forn(i, 0, n) {
        cin >> k;
        forn(j, 0, k) {
            cin >> t1; --t1;
            f[t1].push_back(i);
            b[i].push_back(t1);
            sz[i]++;
        }   
    }
    vector <int> start;
    forn(i, 0, n) if(sz[i]==0) start.push_back(i);
    bfs(start);
    int mx = -1;
    bool pos = true;
    forn(i, 0, n) if(ans[i]==-1) pos = false;
    forn(i, 0, n) mx = max(ans[i], mx);
    if(pos) cout << mx << endl;
    else cout << -1 << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}