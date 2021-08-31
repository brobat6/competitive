#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define N 1000000007
// #define N 1000000


vector<int> p;
int lp[N+1];
int s;
int n;
void sieve() {
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            p.push_back (i);
        }
        for (int j=0; j<(int)p.size() && p[j]<=lp[i] && i*p[j]<=N; ++j)
            lp[i * p[j]] = p[j];
    }
    s = p.size();
}

bool check(int x) {
    return p[x]*p[x+1] <= n;
}

int binsearch() {
    int left = 0;
    int right = s-2;
    int ans = -1;
    while(left <= right) {
        int mid = (left + right)/2;
        if(check(mid)) {
            left = mid + 1;
            ans = mid;
        }
        else {
            right = mid - 1;
        }
    }
    return ans;
}

void solve() {
    cin >> n;
    int i = binsearch();
    cout << p[i]*p[i+1] << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    sieve();

    int T = 1;
    cin >> T;
    forn(i, 1, T+1) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}