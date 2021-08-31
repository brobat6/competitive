#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define MAXN 200100
#define MOD 1000000007
#define BIGINF 1000000000000000000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t; cin >> t; while(t--)
{
    // Code goes here
    int n, k;
    cin >> n >> k;
    int x = 0;
    int op;
    int r;
    cout << x << endl;
    cout.flush();
    cin >> r;
    if(r==1) continue;
    forn(i, n-1) {
        op = x^(x+1);
        // Properties of XOR - 1)a XOR b = c implies a XOR c = b. 2) Commutative 3) Associative
        // In n operations, we want to check every number from 0 to n-1.
        // This code first checks for 0, then 1, then 2.....upto n-1.
        cout << op << endl;
        cout.flush();
        cin >> r;
        if(r==1) break;
        if(r==-1) return 0;
        x++;
    }
}
    return 0;
}
