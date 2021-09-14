#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    int n, x;
    cin >> n >> x;
    int arr[n];
    forn(i, 0, n) cin >> arr[i];
    map<int, pair<int, int>> m;
    if(x==0) {
        map<int, int> m;
        forn(i, 0, n) m[arr[i]]++;
        int max_val = -1;
        for(auto i : m) max_val = max(max_val, i.second);
        cout << max_val << " " << 0 << endl;
        return;
    }
    forn(i, 0, n) {
        m[arr[i]] = {0, 0};
        m[arr[i]^x] = {0, 0};
    }
    forn(i, 0, n) {
        m[arr[i]].first++;
        m[arr[i]^x].first++;
        m[arr[i]^x].second++;
    }
    int max_val = -1;
    for(auto i : m) max_val = max(max_val, i.second.first);
    int min_ops = 2E9;
    for(auto i : m) {
        if(i.second.first == max_val) {
            min_ops = min(min_ops, i.second.second);
        }
    }
    cout << max_val << " " << min_ops << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}