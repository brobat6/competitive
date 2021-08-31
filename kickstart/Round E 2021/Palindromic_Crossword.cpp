#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 1010
#define MOD 1000000007

void _print(int t) {cerr << t << " ";}
void _print(string t) {cerr << t << " ";}
void _print(char t) {cerr << t << " ";}
void _print(double t) {cerr << t << " ";}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}\n";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]\n";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]\n";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]\n";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]\n";}
template <class T, class V> void _print(unordered_map <T, V> umap) {cerr << "{ "; for(auto i : umap) {cerr << "{";_print(i.first); cerr << ", "; _print(i.second); cerr << "} ";} cerr << "}\n";}

int n, m;
map<pair<int, int>, vector<pair<int, int>>> adj;
char arr[MAXN][MAXN];
int ans;

void bfs() {
    queue<pair<int, int>> q;
    forn(i, 0, n+2) {
        forn(j, 0, m+2) {
            if(arr[i][j]!='#' && arr[i][j]!='.') q.push({i, j});
        }
    }
    while(!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for(auto next : adj[{a, b}]) {
            int x = next.first;
            int y = next.second;
            if(arr[x][y]=='.') {
                ans++;
                arr[x][y] = arr[a][b];
                q.push({x, y});
            }
        }
    }
}

void solve() {
    ans = 0;
    for(auto i : adj) adj[i.first].clear();
    cin >> n >> m;
    forn(i, 0, n+2) {
        forn(j, 0, m+2) {
            if(i==0 || i==n+1 || j==0 || j==m+1) {
                arr[i][j] = '#';
                continue;
            }
            cin >> arr[i][j];
        }
    }
    forn(i, 1, n+1) {
        vector <int> v;
        forn(j, 0, m+2) {
            if(arr[i][j]!='#') {
                v.push_back(j);
            }
        }
        int x = v.size();
        map<int, vector<int>> m;
        int k = 1;
        if(x==0) continue;
        m[k].push_back(v[0]);
        forn(z, 1, x) {
            if(v[z] - v[z-1] == 1) m[k].push_back(v[z]);
            else {
                k++;
                m[k].push_back(v[z]);
            }
        }
        for(auto z : m) {
            int x = z.second.size();
            for(int y = 0; y < x/2; y++) {
                adj[{i, z.second[y]}].push_back({i, z.second[x-y-1]});
                adj[{i, z.second[x-y-1]}].push_back({i, z.second[y]});
            }
        }
    }
    forn(i, 1, m+1) {
        vector <int> v;
        forn(j, 0, n+2) {
            if(arr[j][i]!='#') {
                v.push_back(j);
            }
        }
        int x = v.size();
        map<int, vector<int>> m;
        int k = 1;
        if(x==0) continue;
        m[k].push_back(v[0]);
        forn(z, 1, x) {
            if(v[z] - v[z-1] == 1) m[k].push_back(v[z]);
            else {
                k++;
                m[k].push_back(v[z]);
            }
        }
        for(auto z : m) {
            int x = z.second.size();
            for(int y = 0; y < x/2; y++) {
                adj[{z.second[y], i}].push_back({z.second[x-y-1], i});
                adj[{z.second[x-y-1], i}].push_back({z.second[y], i});
            }
        }
    }
    bfs();
    cout << ans << endl;
    forn(i, 1, n+1) {
        forn(j, 1, m+1) {
            cout << arr[i][j];
        }
        cout << endl;
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int T = 1;
    cin >> T;
    forn(I, 1, T+1) {
        cout << "Case #" << I << ": ";
        solve();
    }

    return 0;
}