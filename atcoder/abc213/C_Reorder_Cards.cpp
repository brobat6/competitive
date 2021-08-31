#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    int r, c, n;
    int t1, t2;
    map<int, vector<int>> row;
    map<int, vector<int>> col;
    map<int, pair<int, int>> ans;
    cin >> r >> c >> n;
    forn(i, 0, n) {
        cin >> t1 >> t2;
        row[t1].push_back(i);
        col[t2].push_back(i);
    }
    t1 = 1;
    for(auto i : row) {
        for(auto j : i.second) {
            ans[j].first = t1;
        }
        t1++;
    }
    t1 = 1;
    for(auto i : col) {
        for(auto j : i.second) {
            ans[j].second = t1;
        }
        t1++;
    }
    for(auto i : ans) {
        cout << i.second.first << " " << i.second.second << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // int t; cin >> t; while(t--)
    {solve();}
    return 0;
}