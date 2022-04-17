#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    map<int, int> x, y;
    for(int i = 0; i < 3; i++) {
        int a, b;
        cin >> a >> b;
        x[a]++;
        y[b]++;
    }
    for(auto i : x) {
        if(i.second == 1) cout << i.first << " ";
    }
    for(auto i : y) {
        if(i.second == 1) cout << i.first;
    }
    
    return 0;
}