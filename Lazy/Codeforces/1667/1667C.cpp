#include <bits/stdc++.h>
using namespace std;
#define int long long

void corner(int n) {
    if(n == 1) {
        cout << "1\n1 1";
    } else if(n == 2) {
        cout << "1\n1 1";
    } else if(n == 3) {
        cout << "2\n1 1\n1 2";
    } else {
        cout << "3\n1 1\n2 3\n3 2";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    if(n <= 4) {
        corner(n);
        return 0;
    }
    vector <int> r, c, d;
    
    
    return 0;
}