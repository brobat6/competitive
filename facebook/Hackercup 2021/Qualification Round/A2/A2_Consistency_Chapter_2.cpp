#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

vector <int> adj[26];
int dist[26][26];
string s;
int n, k;
char t1, t2;
map <int, int> m;
bool pos;
int ans;

void bfs(int x) {
    queue<int> q;
    dist[x][x] = 0;
    q.push(x);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto next : adj[curr]) {
            if(dist[x][next] == -1) {
                dist[x][next] = dist[x][curr] + 1;
                q.push(next);
            }
        }
    }
}

void pre() {
    forn(i, 0, 26) adj[i].clear();
    forn(i, 0, 26) forn(j, 0, 26) dist[i][j] = -1;
    forn(i, 0, 26) m[i] = 0;
    cin >> s >> k;
    n = s.length();
    forn(i, 0, n) m[s[i]-'A']++;
    ans = MOD;
    pos = false;
    forn(i, 0, k) {
        cin >> t1 >> t2;
        adj[t1 - 'A'].push_back(t2 - 'A');
    }
}

void solve() {
    pre();
    forn(i, 0, 26) bfs(i);
    // forn(i, 0, 26) {forn(j, 0, 26) cout << dist[i][j] << " "; cout << endl;}
    forn(i, 0, 26) {
        int t3, t = 0;
        bool curr_pos = true;
        forn(j, 0, 26) {
            t3 = dist[j][i] * m[j];
            if(t3 < 0) {
                curr_pos = false;
                break;
            }
            t += t3;
        }
        if(curr_pos) {
            pos = true;
            ans = min(ans, t);
        }
    }
    if(pos) cout << ans << endl;
    else cout << -1 << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("consistency_chapter_2_input.txt", "r", stdin);
    // freopen("consistency_chapter_2_output.txt", "w", stdout);

    int T = 1;
    cin >> T;
    forn(I, 1, T+1) {
        cout << "Case #" << I << ": ";
        solve();
    }

    return 0;
}