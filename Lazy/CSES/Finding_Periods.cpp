#include <bits/stdc++.h>
using namespace std;

// NOT AC 

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    int n = (int)s.length();
    auto v = prefix_function(s);
    int p = n - v.back();
    // for(auto i : v) cout << i << ' '; cout << '\n';
    vector <int> ans;
    int j = p;
    for(int i = p; i < n; i += p) {
        ans.push_back(i);
        j = i;
    }
    for(int i = j + 1; i < n; i++) {
        if(v[i] == v.back()) ans.push_back(i);
    }
    ans.push_back(n);

    for(auto i : ans) cout << i << " ";
    
    return 0;
}