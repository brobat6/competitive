#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector <string> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int mn = 0;
    int mx = -1;
    for(int i = 0; i < n; i++) {
        mx += (int)s[i].length() + 1;
        mn = max(mn, (int)s[i].length());
    }
    for(int i = mn; i <= mx; i++) {
        vector <int> v;
        v.push_back(-1);
        for(int j = 0; j < n; j++) {
            int curr = s[j].length();
            int ind = (int)v.size() - 1;
            if(v[ind] + 1 + curr <= i) {
                v[ind] += 1 + curr;
            } else {
                v.push_back(curr);
            }
        }
        cout << "(" << i << "," << (int)v.size() << ")\n";
    }
    
    return 0;
}
/*
xxx_xxx_xxx_xxx_xxx_xxx
ukraine_trygub
glory_anton_and
*/