#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    map<int, int> m;
    for(int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        m[x]++;
    }
    vector <int> v;
    for(auto i : m) v.push_back(i.first);
    if((int)v.size() == 2) {
        if(m[v[0]] == 3 || m[v[1]] == 3) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    
    return 0;
}