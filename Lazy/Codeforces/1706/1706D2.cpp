#include <bits/stdc++.h>
using namespace std;
#define int long long

int find(int x) {
    set <int> s;
    for(int i = 1; i <= x; i++) {
        s.insert(x / i);
    }
    return s.size();
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for(int i = 10000; i < 10100; i++) {
        cout << find(i) << '\n';
    }
    
    return 0;
}