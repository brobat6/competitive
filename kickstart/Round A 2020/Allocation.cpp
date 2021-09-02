#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    int n, b;
    cin >> n >> b;
    vector <int> arr(n);
    forn(i, 0, n) cin >> arr[i];
    sort(arr.begin(), arr.end());
    int x = 0;
    forn(i, 0, n) {
        if(x + arr[i] > b) {
            cout << i << endl;
            return;
        }
        x += arr[i];
    }
    cout << n << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int T = 1;
    cin >> T;
    forn(I, 1, T+1) {
        cout << "Case #" << I << ": ";
        solve();
    }

    return 0;
}