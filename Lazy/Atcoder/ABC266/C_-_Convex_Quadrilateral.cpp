#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

bool check(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d) {
    // check that c and d are on opposite sides of AB.
    int t1 = c.x*(b.y - a.y) + c.y*(a.x - b.x) + a.y*(b.x - a.x) - a.x*(b.y - a.y);
    int t2 = d.x*(b.y - a.y) + d.y*(a.x - b.x) + a.y*(b.x - a.x) - a.x*(b.y - a.y);
    // cout << t1 << ' ' << t2 << '\n';
    assert(t1 != 0 && t2 != 0);
    if(t1 > 0) return t2 < 0;
    return t2 > 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<pair<int, int>> p(4);
    for(int i = 0; i < 4; i++) {
        cin >> p[i].first >> p[i].second;
    }
    cout << (check(p[0], p[2], p[1], p[3]) && check(p[1], p[3], p[2], p[0]) ? "Yes" : "No");
    
    return 0;
}