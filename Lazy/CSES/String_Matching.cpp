#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    string t;
    cin >> t;
    t += '0';
    s = '0' + s;
    int n = s.length();
    int m = t.length();
    vector <int> pi(n);
    pi[0] = 0;
    for(int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while(j > 0 && s[i] != t[j]) {
            j = pi[j - 1];
        }
        if(s[i] == t[j]) {
            j++;
        }
        pi[i] = j;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += (pi[i] == m - 1);
        // cout << s[i] << " " << pi[i] << '\n';
    }
    cout << ans;
    
    return 0;
}