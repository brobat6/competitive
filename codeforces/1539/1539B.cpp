#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define MAXN 200100
#define MOD 1000000007
#define BIGINF 1000000000000000000

int n, q;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // int t; cin >> t; while(t--)
// {
    // Code goes here
    cin >> n >> q;
    cin >> s;
    int d[26][n+1];
    forn(i, 26) {
        d[i][0] = 0;
        int temp = 0;
        forn(j, n) {
            char a = s[j];
            if(int(a)-97==i) temp++;
            d[i][j+1] = temp;
        }
    }
    forn(i, q) {
        int l, r;
        int ans = 0;
        cin >> l >> r;
        forn(j, 26) {
            ans += (d[j][r] - d[j][l-1])*(j+1);
        }
        cout << ans << "\n";
    }
// }
    return 0;
}
