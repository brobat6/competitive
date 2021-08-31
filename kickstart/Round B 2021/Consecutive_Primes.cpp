#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

bool prime(int x) {
    if(x%2==0) return false;
    for(int d = 3; d*d<=x; d+=2) {
        if(x%d==0) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    if(n < 15) {
        cout << 6 << endl;
        return;
    }
    int s = 0;
    int l = 0;
    vector<int> v;
    int x = floor(sqrt(n));
    int i = 0;
    while(s < 2) {
        if(prime(x - i)) {
            s++;
            v.push_back(x - i);
        }
        i++;
    }
    x = floor(sqrt(n)) + 1;
    i = 0;
    while(l < 1) {
        if(prime(x+i)) {
            l++;
            v.push_back(x + i);
        }
        i++;
    }
    sort(v.begin(), v.end());
    if(v[2]*v[1] > n) cout << v[0]*v[1];
    else cout << v[2]*v[1];
    cout << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    forn(i, 1, T+1) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}