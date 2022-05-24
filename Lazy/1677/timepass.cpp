#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for(int i = 1; i <= 100; i++) {
        cout << "int t" << i << " = " << i << ";\n";
    }
    cout << "cout << ";
    for(int i = 1; i <= 99; i++) {
        cout << "t" << i << " + ";
    }
    cout << "t100 << '\\n';";
    
    return 0;
}