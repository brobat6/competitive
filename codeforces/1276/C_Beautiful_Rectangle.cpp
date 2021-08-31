//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 400100
#define MOD 1000000007

int n;
int arr[MAXN];
vector <pair<int,int>> v;
map <int, int> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    cin >> n;
    forn(i, n) cin >> arr[i];
    forn(i, n) m[arr[i]] += 1;

    return 0;
}
