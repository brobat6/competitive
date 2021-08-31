//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 1000000100

int n, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    cin >> t;
while(t--) {
    cin >> n >> k;
    if(n%3==0) {
        cout << n/3 << " " << n/3 << " " << n/3 << endl;
        continue;
    }
    if(n%2==1) {
        cout << 1 << " " << n/2 << " " << n/2 << endl;
        continue;
    }
    
}
    return 0;
}
