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
    int sum = accumulate(v.begin(), v.end(), 0ll);
    if(sum < n * (n + 1)/2) {
        cout << "NO" << endl;
        return;
    }
    if(sum == n * (n + 1)/2) {
        sort(v.begin(), v.end());
        forn(i, 0, n) {
            if(v[i] != i + 1) {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES " << n + 1 << endl;
        return;
    }
    int z = sum - n * (n + 1)/2;
    vector <int> f;
    for(int i = 1; i <= sqrt(z); i++) {
        if(z % i == 0) {
            if(i * i == z) {
                f.push_back(i);
            } else {
                f.push_back(i);
                f.push_back(z/i);
            }
        }
    }
    for(auto i : f) {
        if(i <= n || i >= (int)2E7) continue;
        map<int, int> m;
        for(auto j : v) m[j % i]++;
        bool yes = true;
        forn(j, 1, n + 1) {
            if(m[j] != 1) {
                yes = false;
                break;
            }
        }
        if(yes) {
            cout << "YES " << i << endl;
            return;
        }
    }
    cout << "NO" << endl;
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