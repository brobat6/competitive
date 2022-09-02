#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        vector <int> v(n + 2, -(int)1E9);
        for(int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        multiset <int> ms;
        for(int i = 1; i <= n + 1; i++) {
            ms.insert(abs(v[i] - v[i - 1]));
        }
        for(int i = 0; i < q; i++) {
            int j, p;
            cin >> j >> p; // v[j] = p.
            ms.erase(ms.find(abs(v[j] - v[j - 1])));
            ms.erase(ms.find(abs(v[j] - v[j + 1])));
            v[j] = p;
            ms.insert(abs(v[j] - v[j - 1]));
            ms.insert(abs(v[j] - v[j + 1]));
            cout << (*ms.begin()) << '\n';
        }
    }
    
    return 0;
}