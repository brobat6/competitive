#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

void solve() {
    int n;
    cin >> n;
    vector <int> v(n);
    forn(i, 0, n) cin >> v[i];
    vector <int> ans(n, 0);
    // for(int i = 0; i < n; i++) {
    //     vector <int> w = v;
    //     sort(w.begin(), w.begin() + i + 1);
    //     // for(auto i : w) cout << i << " ";
    //     // cout << endl;
    //     for(int j = 0; j < n; j++) ans[j] += w[j];
    // }
    vector <int> z;
    for(int i = 0; i < n; i++) {
        if(v[i] == 0) z.push_back(i);
    }
    for(int i = 0; i < n; i++) {
        if(i >= (int)z.size()) ans[i] += n - i;
        else ans[i] += (z[i] - i);
        if(v[i] == 1) ans[i] += i;
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}