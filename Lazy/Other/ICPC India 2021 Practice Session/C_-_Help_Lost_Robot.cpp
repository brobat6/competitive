#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        pair<int, int> a, b;
        cin >> a.first >> a.second >> b.first >> b.second;
        if(a.first == b.first) {
            cout << (a.second < b.second ? "up" : "down") << '\n';
        } else if(a.second == b.second) {
            cout << (a.first < b.first ? "right" : "left") << '\n';
        } else {
            cout << "sad" << '\n';
        }
    }
    
    return 0;
}