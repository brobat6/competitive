#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int x, y, n;
    cin >> x >> y >> n;

    if(x*3 >= y) {
        cout << (n/3)*y + (n%3)*x;
    } else {
        cout << n*x;
    }
    
    return 0;
}