#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector <pair<int, int>> a, b;
int sx, sy;
pair<int, int> jolly;
const int INF = (int)1E18;

int distance(pair<int, int> &x, pair<int, int> &y) {
    return (x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second);
}

bool poss(vector<int> &order, int curr, vector<pair<int, int>> sweets) {
    // return true if this order of children, assuming we're at child curr and "sweets" are left, is possible.
    pair<int, int> jolly = {sx, sy};
    if(curr == n) {
        if(sweets[0].first == sx && sweets[0].second == sy) return true;
        return false;
    }
    vector <pair<int, int>> dist;
    int mn_dist = (int)1E18;
    bool has_j = false;
    for(int i = 0; i < (int)sweets.size(); i++) {
        dist.push_back({i, distance(sweets[i], a[order[curr]])});
        mn_dist = min(mn_dist, dist[i].second);
        if(sweets[i] == jolly) {
            has_j = true;
        }
    }
    if(!has_j) return false;
    vector <int> pos;
    for(int i = 0; i < (int)dist.size(); i++) {
        if(dist[i].second == mn_dist) pos.push_back(i);
    }
    // recur for all "possible" values.
    for(auto ind : pos) {
        vector <pair<int, int>> ns;
        for(int i = 0; i < (int)sweets.size(); i++) {
            if(ind == i) continue;
            ns.push_back(sweets[i]);
        }
        auto x = poss(order, curr + 1, ns);
        if(x) return true;
    }
    return false;
}

bool func(vector<int> &o, int curr, vector<int> &o2) {
    if(curr == n) return true;
    int mn_dist = (int)6E18;
    for(int i = curr; i <= n; i++) {
        mn_dist = min(mn_dist, distance(b[o2[i]], a[o[curr]]));
    }
    if(mn_dist == distance(b[o2[curr]], a[o[curr]])) {
        return func(o, curr + 1, o2);
    }
    return false;
}

void solve() {
    cin >> n;
    a.resize(n);
    b.resize(n + 1);
    map<pair<int, int>, int> sw;
    vector <int> c(n);
    for(int i = 0; i < n; i++) c[i] = i;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a[i] = {x, y};
    }
    for(int i = 0; i <= n; i++) {
        int x, y; cin >> x >> y;
        b[i] = {x, y};
        sw[{x, y}] = i;
    }
    sx = b[0].first;
    sy = b[0].second;
    jolly = b[0];
    bool exists = false;
    vector <int> a1, a2; // ans, if pos >= 0.
    do {
        // pre-process the permutation such that repeated cases don't exist.
        bool rep = false;
        for(int i = 0; i < n; i++) {
            if(rep) break;
            for(int j = i + 1; j < n; j++) {
                if(a[i] == a[j] && c[i] > c[j]) {
                    rep = true;
                    break;
                }
            }
        }
        if(rep) continue;

        // find if the current order of childen can do it.
        auto x = poss(c, 0, b);
        if(x) {
            exists = true;
            a1 = c;
            break;
        }
    } while(next_permutation(c.begin(), c.end()));
    cout << (exists ? "POSSIBLE" : "IMPOSSIBLE") << '\n';
    if(!exists) return;
    sort(c.begin(), c.end());
    c.push_back(n);
    exists = false;
    // for(auto i : a1) cout << i + 1 << " ";
    do {
        if(c[n] != 0) continue;
        auto x = func(a1, 0, c);
        // for(auto i : c) cout << i << " ";
        // cout << x << '\n';
        if(x) {
            exists = true;
            a2 = c;
            break;
        }
    } while(next_permutation(c.begin(), c.end()));
    // cout << (int)a1.size() << " " << (int)a2.size() << '\n';
    for(int i = 0; i < n; i++) {
        cout << a1[i] + 1 << " " << a2[i] + 1 << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    
    return 0;
}