#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

vector <int> parent, sz;
vector <pair<int, int>> ans;
vector <int> deg; // degrees needed
vector <int> sat; // degrees satisfied so far
int n, m;
int t1, t2;
map <int, deque<int>> need; // degrees that have to be satisfied in a given component.

int find(int x) {
    if(x==parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    int c = find(a);
    int d = find(b);
    if(d!=c) {
        parent[d] = c;
        sz[c] += sz[d];
    }
}

void unite_comp(int a, int b) {
    int c = find(a);
    int d = find(b);
    if(sz[d] > sz[c]) swap(c, d);
    ans.push_back({need[c][0], need[d][0]});
    need[c].pop_front();
    need[d].pop_front();
    parent[d] = c;
    for(auto i : need[d]) {
        need[c].push_back(i);
    }
    need[d].clear();
}

void solve() {
    cin >> n >> m;
    deg.resize(n);
    sat.resize(n, 0);
    parent.resize(n);
    sz.resize(n, 1);
    forn(i, 0, n) {
        cin >> deg[i];
        parent[i] = i;
    }
    if(accumulate(deg.begin(), deg.end(), 0ll) != 2 * (n - 1)) {
        cout << -1;
        return;
    }
    forn(i, 0, m) {
        cin >> t1 >> t2;
        --t1; --t2;
        if(find(t1) == find(t2)) {
            cout << -1;
            return;
        }
        unite(t1, t2);
        sat[t1]++;
        sat[t2]++;
    }
    // forn(i, 0, n) cout << sat[i] << " ";
    map<int, int> deg_left;
    forn(i, 0, n) {
        if(sat[t1] > deg[t1]) {
            cout << -1;
            return;
        }
        forn(j, 0, deg[i] - sat[i]) {
            need[find(i)].push_back(i);
        }
        if(deg[i] - sat[i] > 0) 
        deg_left[find(i)] += deg[i] - sat[i];
    }
    set <pair<int, int>> s; 
    for(auto i : deg_left) {
        s.insert({i.second, i.first});
        // cout << i.first + 1 << " " << i.second << ":";
        // for(auto j : need[i.first]) cout << j + 1 << " ";
        // cout << endl;
    }
    int done = 0;
    while(done < n - m - 1) {
        // Unite the beginning and end elements of the set.
        if(s.empty()) {
            cout << -1;
            return;
        }
        pair<int, int> f = *s.begin();
        pair<int, int> g = *(--s.end());
        // cout << f.second + 1 << " " << f.first << " " << g.second + 1 << " " << g.first << endl;
        if(find(f.second) == find(g.second)) {
            cout << -1;
            return;
        }
        // if(f.first == 0 || g.first == 0) {

        // }
        s.erase(s.begin());
        s.erase(--s.end());
        if(f.first > 1) {
            s.insert({f.first - 1, f.second});
        }
        if(g.first > 1) {
            s.insert({g.first - 1, g.second});
        }
        unite_comp(f.second, g.second);
        done++;
    }
    if(!s.empty()) {
        cout << -1;
        return;
    }
    for(auto i : ans) {
        cout << i.first + 1 << " " << i.second + 1 << endl;
    }
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}