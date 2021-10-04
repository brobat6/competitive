#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

map<char, int> m;

bool comp(string A, string B) {
    forn(i, 0, min(A.length(), B.length())) {
        if(m[A[i]]==m[B[i]]) continue;
        return m[A[i]] < m[B[i]];
    }
    return A.length() < B.length();
}

void solve() {
    string x; cin >> x;
    int n; cin >> n;
    forn(i, 0, 26) m[x[i]] = i;
    vector <string> v(n);
    forn(i, 0, n) cin >> v[i];
    sort(v.begin(), v.end(), comp);
    for(auto i : v) cout << i << endl;
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