#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    int n, k;
    cin >> n >> k;
    int a, t;
    cin >> a;
    priority_queue<pair<int, int>> pq;
    map<int, pair<int, int>> m;
    forn(i, 0, n-1) {
        cin >> t;
        pq.push({t - a, i});
        m[i] = {t - a, 1};
        a = t;
    }
    forn(i, 0, k) {
        auto x = pq.top();
        if(x.first == 1) {
            cout << 1 << endl;
            return;
        }
        pq.pop();
        m[x.second].second++;
        pq.push({ceil(m[x.second].first/(double)m[x.second].second), x.second});
    }
    cout << pq.top().first << endl;
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