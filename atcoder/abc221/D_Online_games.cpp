#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    forn(i, 0, n) {
        cin >> v[i].first >> v[i].second;
        v[i].second += v[i].first;
    }
    sort(v.begin(), v.end());
    vector <int> ans(n+1, 0);
    priority_queue<int, vector<int>, greater<int>> pq;
    int curr = v[0].first; 
    pq.push(v[0].second);
    int count = 1;
    forn(i, 1, n) {
        while(!pq.empty() && pq.top() < v[i].first) {
            ans[count] += pq.top() - curr;
            curr = pq.top();
            pq.pop();
            count--;
        }
        ans[count] += v[i].first - curr;
        curr = v[i].first;
        pq.push(v[i].second);
        count++;
    }
    while(!pq.empty()) {
        ans[count] += pq.top() - curr;
        curr = pq.top();
        pq.pop();
        count--;
    }
    forn(i, 1, n+1) cout << ans[i] << " ";
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}