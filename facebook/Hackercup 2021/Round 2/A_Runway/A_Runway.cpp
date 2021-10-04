#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 1000100;
const int MOD = 1000000007;

int n, m;
vector <vector<int>> v;
int ans, common;

void pre() {
    cin >> n >> m;
    ans = 0;
    common = 0;
    v.resize(n + 5);
    forn(i, 0, n+1) v[i].resize(m);
    forn(i, 0, n+1) {
        forn(j, 0, m) {
            cin >> v[i][j];
        }
        sort(v[i].begin(), v[i].end());
    }
}

void solve() {
    pre();
    forn(i, 0, n) {
        // Compare changes in v[i] and v[i+1].
        int temp = 0, a = 0, b = 0;
        while(a < m || b < m) {
            if(a >= m) {
                temp++; b++; continue;
            }
            if(b >= m) {
                temp++; a++; continue;
            }
            if(v[i][a] == v[i+1][b]) {
                a++; b++; continue;
            }
            if(v[i][a] < v[i+1][b]) {
                temp++; a++; continue;
            }
            if(v[i][a] > v[i+1][b]) {
                temp++; b++; continue;
            }
        }
        temp /= 2;
        ans += temp;
    }
    vector <int> c = v[0];
    forn(i, 1, n+1) {
        vector <int> temp;
        int a = 0, b = 0;
        while(a < c.size() && b < m) {
            if(c[a] == v[i][b]) {
                temp.push_back(c[a]);
                a++; b++; continue;
            }
            if(c[a] < v[i][b]) {
                a++; continue;
            }
            if(c[a] > v[i][b]) {
                b++; continue;
            }
        }
        c = temp;
    }
    map <int, int> mp;
    for(auto i : c) mp[i]++;
    int common = c.size();
    // for(auto i : mp) cout << i.first << " " << i.second << endl;
    for(auto i : mp) {
        // Check amount of mp.
        int temp = i.second;
        // Check i.first. Whenever i.first comes more than i.second times and temp > 0, reduce temp and common.
        forn(j, 1, n + 1) {
            int x = upper_bound(v[j].begin(), v[j].end(), i.first) - lower_bound(v[j].begin(), v[j].end(), i.first);
            if(x > i.second) {
                common -= min(temp, x - i.second);
                temp -= min(temp, x - i.second);
            }
        }
    }
    // for(auto i : c) cout << i << ""
    // cout << ans << " " << c.size() << endl;
    cout << max(0ll, ans - (m - common)) << endl;
    // cout << max(0ll, ans - m) << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("runway_input.txt", "r", stdin);
    // freopen("runway_output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    forn(I, 1, T + 1) {
        cout << "Case #" << I << ": ";
        solve();
    }

    return 0;
}