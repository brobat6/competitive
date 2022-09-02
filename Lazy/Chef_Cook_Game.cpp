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
        deque <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        v.pop_back();
        while(!v.empty() && v.front() == 0) {
            v.pop_front();
        }
        if(v.empty() || ((int)v.size() == 1 && v.front() % 2 == 0)) {
            cout << "Cook" << '\n';
        } else {
            cout << "Chef" << '\n';
        }
    }
    
    return 0;
}