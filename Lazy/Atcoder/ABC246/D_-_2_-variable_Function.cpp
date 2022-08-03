#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    int x = 1E18;
    int a = 0;
    int b = 1E6;
    while(a <= b) {
        int c = (a + b)*(a*a + b*b);
        if(c >= n) {
            x = min(x, c);
            b--;
        } else {
            a++;
        }
    }
    cout << x;
    return 0;
}