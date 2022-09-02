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
        int a = 0, b = 0, c = 0, d = 0; // -1, 0, 1, |x| > 1
        int o = 0;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if(x == 0) b++;
            else if(x == -1) a++;
            else if(x == 1) c++;
            else {
                d++;
                o = x;
            }
        }
        if(d >= 2) {
            cout << "no" << '\n';
            continue;
        }
        vector <int> v;
        map<int, int> p;
        if(a > 0) v.push_back(-1);
        if(a > 1) v.push_back(-1);
        if(c > 0) v.push_back(1);
        if(c > 1) v.push_back(1);
        if(b > 0) v.push_back(0);
        if(b > 1) v.push_back(0);
        if(d > 0) v.push_back(o);
        bool check = true;
        for(auto i : v) p[i] = 1;
        for(int i = 0; i < (int)v.size(); i++) {
            for(int j = i + 1; j < (int)v.size(); j++) {
                if(p.find(v[i] * v[j]) == p.end()) {
                    check = false;
                }
            }
        }
        cout << (check ? "yes" : "no") << '\n';
    }
    
    return 0;
}