#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

struct Segment {
    int first;
    int second;
    int index;
};

bool comp(Segment A, Segment B) {
    if(A.first == B.first) 
        return(A.second < B.second);
    return A.first < B.first;
}

void solve() {
    int n;
    cin >> n;
    int t1, t2;
    Segment v[n];
    int yellow_end = 0;
    int blue_end = 0;
    int ans[n];
    forn(i, 0, n) {
        cin >> t1 >> t2;
        v[i].first = t1;
        v[i].second = t2;
        v[i].index = i;
    }
    sort(v, v + n, comp);
    forn(i, 0, n) {
        if(v[i].first >= blue_end && v[i].first >= yellow_end) {
            yellow_end = v[i].second;
            ans[v[i].index] = 1;
        }
        else {
            if(blue_end > yellow_end) {
                ans[v[i].index] = 1;
                yellow_end = v[i].second;
            }
            else {
                ans[v[i].index] = 0;
                blue_end = v[i].second;
            }
        }
    }
    forn(i, 0, n) cout << ans[i];
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t; cin >> t; while(t--)
{
    // Code goes here
    solve();
}
    return 0;
}