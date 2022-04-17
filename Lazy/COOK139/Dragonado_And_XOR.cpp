#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

void solve() {
    int n;
    cin >> n;
    vector <int> v(n);
    forn(i, 0, n) cin >> v[i];
    if(n > 64) n = 64;
    map<int, vector<pair<int, int>>> m;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            m[__builtin_popcount(v[i] ^ v[j])].push_back({i, j});
        }
    }
    for(auto i : m) {
        int z = i.second.size();
        for(int j = 0; j < z; j++) {
            for(int k = j + 1; k < z; k++) {
                set <int> s;
                s.insert(i.second[j].first);
                s.insert(i.second[j].second);
                s.insert(i.second[k].first);
                s.insert(i.second[k].second);
                if(s.size() == 4) {
                    cout << i.second[j].first+1 << " " << i.second[j].second+1 << " " << i.second[k].first+1 << " " << i.second[k].second+1;
                    cout << endl;
                    return;
                }
            }
        }
    }
    cout << -1 << endl;
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}