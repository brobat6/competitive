#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector <int> p(n);
    p[0] = 0;
    for(int i = 1; i < n; i++) {
        cin >> p[i];
        --p[i];
    }
    int ans = 0;
    int curr = n - 1;
    while(curr) {
        ans++;
        curr = p[curr];
    }
    cout << ans;
    
    return 0;
}