#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        cout << "Case #" << I << ": ";
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<bool> v(4, false);
        for(int i = 0; i < n; i++) {
            if(s[i] >= 'a' && s[i] <= 'z') v[0] = true;
            if(s[i] >= 'A' && s[i] <= 'Z') v[1] = true;
            if(s[i] >= '0' && s[i] <= '9') v[2] = true;
            if(s[i] == '&' || s[i] == '*' || s[i] == '@' || s[i] == '#') v[3] = true;
        }
        cout << s;
        if(!v[0]) {cout << 'a'; n++;}
        if(!v[1]) {cout << 'A'; n++;}
        if(!v[2]) {cout << '1'; n++;}
        if(!v[3]) {cout << '#'; n++;}
        while(n < 7) {
            cout << 'a'; n++;
        }
        cout << '\n';
    }
    
    return 0;
}