#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int mod = 1000000007;
double EPS = 1e-7;

int32_t main()
{
    fastio;
    int n, x;
    cin >> n >> x;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (x % i == 0 && x/i <=n)
            ans++;
    }
    cout << ans << "\n";
}