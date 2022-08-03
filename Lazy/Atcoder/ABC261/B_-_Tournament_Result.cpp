#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            string t;
            t += v[i][j];
            t += v[j][i];
            if(t == "WL" || t == "LW" || t == "DD") continue;
            cout << "incorrect";
            return 0;
        }
    }
    cout << "correct";
    
    return 0;
}