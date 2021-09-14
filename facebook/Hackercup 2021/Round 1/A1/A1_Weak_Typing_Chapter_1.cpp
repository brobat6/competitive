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
    vector <char> v(n);
    forn(i, 0, n) cin >> v[i];
    // Always change at O or X.
    char curr = '0';
    int ans = 0;
    forn(i, 0, n) {
        if(v[i]=='O') {
            if(curr=='0') curr = 'O';
            else if(curr=='X') {
                curr = 'O';
                ans++;
            }
        }
        if(v[i]=='X') {
            if(curr=='0') curr = 'X';
            else if(curr=='O') {
                curr = 'X';
                ans++;
            }
        }
    }
    cout << ans << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("weak_typing_chapter_1_input.txt", "r", stdin);
    // freopen("weak_typing_chapter_1_output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    forn(I, 1, T + 1) {
        cout << "Case #" << I << ": ";
        solve();
    }

    return 0;
}