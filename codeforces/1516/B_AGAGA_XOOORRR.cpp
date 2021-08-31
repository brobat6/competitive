// https://codeforces.com/contest/1516/problem/B

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define debug(x) cout << #x << " is " << x << endl
using namespace std;
#define MAXN 2200
#define MOD 1000000007

int n, arr[MAXN], pre[MAXN], suff[MAXN];

bool func() {
    cin >> n;
    forn(i, n) cin >> arr[i];
    pre[0] = arr[0];
    suff[0] = arr[n-1];
    forn(i, n-2) {
        pre[i+1] = pre[i]^arr[i+1];
        suff[i+1] = suff[i]^arr[n-2-i];
    }
    forn(i, n-1) if(pre[i]==suff[n-2-i]) return true;
    forn(i, n-1) {
        forn(j, n-i-2) {
            if(pre[i]==suff[j]) {
                int x = arr[i+1];
                for(int k=(i+2); k<j; k++) {
                    x = x^arr[k];
                }
                if(pre[i]==x) return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    cin >> t;
while(t--) {
    if(func()) cout << "YES" << endl;
    else cout << "NO" << endl;
}
    return 0;
}
