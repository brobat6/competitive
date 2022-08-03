#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int a, b;
    cin >> a >> b;
    if(b == 0) cout << "1 0";
    else if(a == 0) cout << "0 1";
    else {
        long double x = tanhl(a*1.0/b);
        cout << setprecision(15) << sinl(x) << " " << cosl(x);
    }
    
    return 0;
}