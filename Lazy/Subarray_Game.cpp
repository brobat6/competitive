#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector <bool> c(n, false);
        c[0] = true;
        c[n - 1] = true;
        for(int i = 1; i < n - 1; i++) {
            if(v[i] > v[i - 1] && v[i] > v[i + 1]) c[i] = true;
            if(v[i] < v[i - 1] && v[i] < v[i + 1]) c[i] = true;
        }
        vector <int> w;
        for(int i = 0; i < n; i++) {
            if(c[i]) w.push_back(i);
        }
        vector <int> x;
        for(int i = 1; i < (int)w.size(); i++) {
            x.push_back(w[i] - w[i - 1] - 1);
        }
        int ans = 0;
        for(auto i : x) ans ^= i;
        cout << (ans == 0 ? "Bob" : "Alice") << '\n';
    }
    
    return 0;
}