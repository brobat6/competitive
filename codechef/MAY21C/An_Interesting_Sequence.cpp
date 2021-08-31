//

#include <bits/stdc++.h>
#define forn(i, n) for (long long i = 0; i < n; i++)
using namespace std;
#define MAXN 2000100
#define MOD 1000000007

long long k;
long long ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
while(t--) {
    ans = 0;
    scanf("%d", &k);
    forn(i, 2*k) ans += __gcd(k + ((i+1)*(i+1)), k + ((i+2)*(i+2)));
    printf("%d\n", ans);
}
    return 0;
}