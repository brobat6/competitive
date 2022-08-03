#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    int n = s.length();
    vector<string> ans;
    vector <int> g = {1, 2, 3};
    for(auto a : g) for(auto b : g) for(auto c : g) for(auto d : g) {
        if(a + b + c + d != n) continue;
        deque<char> t;
        for(auto i : s) t.push_back(i);
        string u = "";
        for(int i = 0; i < a; i++) {
            u += t.front();
            t.pop_front();
        }
        u += ".";
        for(int i = 0; i < b; i++) {
            u += t.front();
            t.pop_front();
        }
        u += ".";
        for(int i = 0; i < c; i++) {
            u += t.front();
            t.pop_front();
        }
        u += ".";
        for(int i = 0; i < d; i++) {
            u += t.front();
            t.pop_front();
        }
        ans.push_back(u);
    }
    vector <string> z;
    for(auto s : ans) {
        bool pos = true;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                if(i == 0 || s[i - 1] == '.') {
                    if(i == n - 1 || s[i + 1] == '.') {

                    } else {
                        pos = false;
                    }
                } else {

                }
            }
        }
        if(pos) z.push_back(s);
    }
    if(z.empty()) cout << -1;
    else for(auto i : z) cout << i << " ";
    
    return 0;
}