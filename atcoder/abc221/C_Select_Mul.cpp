#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

bool check(vector<char>&v, int sp, int n) {
    if(v[0] == '0') return false;
    if(v[sp] == '0') return false;
    return true;
}

int find_prod(vector<char>&v, int sp, int n) {
    string a, b;
    forn(i, 0, sp) a += v[i];
    forn(i, sp, n) b += v[i];
    return (int)(stoi(a) * stoi(b));
}

void solve() {
    string s; cin >> s; 
    int n = s.length();
    vector<char> v(n);
    forn(i, 0, n) v[i] = s[i];
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int ans = 0;
    do {
        forn(i, 1, n) {
            if(check(v, i, n)) {
                ans = max(ans, find_prod(v, i, n));
            }
        }
    } while(prev_permutation(v.begin(), v.end()));
    cout << ans << endl;
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