//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 200100
#define MOD 1000000007

long long n, m;
vector<vector<long long>> fac(5000001,vector<long long>());
void compute()
{
    for (long long i = 1; i <= 500000; i++)
    {
        for(long long j=i;j<=500000;j+=i)
        {
            fac[j].push_back(i);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    compute();
    long long t;
    cin >> t;
while(t--) {
    long long ans = 0;
    cin >> n >> m;
    for(long long b=2; b<=min(m, n); b++) {
        long long x = m - (m%b);
        for(auto it: fac[x]) {
            if(it < b) ans += 1;
        }
    }
    if(n>m) {
        ans += (n*(n-1))/2;
        ans -= (m*(m-1))/2;
    }
    cout << ans << endl;
}
    return 0;
}



