#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // int t; cin >> t; while(t--)
{
    // Code goes here
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    int temp;
    forn(i, 0, n) {
        cin >> temp;
        v.push_back({temp, i+1});
    }
    sort(v.begin(), v.end());
    cout << v[n-2].second;
}
    return 0;
}