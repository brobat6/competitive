//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 2000100
#define MOD 1000000007

int k;
int arr[MAXN];
long long ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
while(t--) {
    ans = 0;
    cin >> k;
    forn(i, (2*k)+1) {
        arr[i] = k + ((i+1)*(i+1));
    }
    forn(i, 2*k) ans += __gcd(arr[i], arr[i+1]);
    cout << ans << endl;
}
    return 0;
}