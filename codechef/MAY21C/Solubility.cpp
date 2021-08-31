//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 200100
#define MOD 1000000007

int x, a, b;
// int arr[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t; cin >> t;
while(t--) {
    cin >> x >> a >> b;
    int ans = ((100 - x)*b) + a;
    ans *= 10;
    cout << ans << endl;
}
    return 0;
}
