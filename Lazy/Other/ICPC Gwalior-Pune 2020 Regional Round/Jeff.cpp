#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, j;
        cin >> n >> j;
        --j;
        vector<char> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int tt = 0;
        for(int i = j + 1; i < n; i++) {
            if(v[i] == '#') tt += 2;
            else tt++;
        }
        cout << (tt < n ? "JAY" : "JEFF") << '\n';
    }
    
    return 0;
}