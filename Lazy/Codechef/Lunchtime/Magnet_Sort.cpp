#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

int solve() {
    int n;
    cin >> n;
    vector <int> v(n);
    vector <char> p(n);
    forn(i, 0, n) cin >> v[i];
    forn(i, 0, n) cin >> p[i];
    vector <int> s = v;
    sort(s.begin(), s.end());
    if(is_sorted(v.begin(), v.end())) {
        return 0;
    }
    int cnt = 0;
    forn(i, 0, n) if(p[i] == 'N') cnt++;
    if(cnt == 0 || cnt == n) {
        return -1;
    }
    if(p[0] != p[n - 1]) {
        return 1;
    }
    char c = p[0];
    bool two_ops = true;
    bool f = true;
    forn(i, 0, n) {
        if(p[i] != c) {
            break;
        }
        if(p[i] == c && v[i] != s[i]) {
            f = false;
            break;
        }
    }
    if(f) two_ops = false;
    f = true;
    for(int i = n - 1; i >= 0; i--) {
        if(p[i] != c) {
            break;
        }
        if(p[i] == c && v[i] != s[i]) {
            f = false;
            break;
        }
    }
    if(f) two_ops = false;
    return (two_ops ? 2 : 1);
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        cout << solve() << endl;
    }

    return 0;
}