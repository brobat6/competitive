#include <bits/stdc++.h>
using namespace std;
#define int long long

int comp(pair<int, int> &a, pair<int, int> &b) {
    return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
}

const int INF = (int)1E18;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector <int> a(k);
    for(int i = 0; i < k; i++) {
        cin >> a[i];
        --a[i];
    }
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    
    vector<int> dist(n, INF);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            dist[i] = min(dist[i], comp(v[i], v[a[j]]));
        }
    }
    int x = *max_element(dist.begin(), dist.end());
    cout << setprecision(15) << sqrtl(x);
    
    return 0;
}