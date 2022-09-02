#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    set<vector<int>> p;
    vector <int> v(m);
    iota(v.begin(), v.end(), 1);
    do {
        auto q = v;
        while((int)q.size() > n) q.pop_back();
        sort(q.begin(), q.end());
        p.insert(q);
    } while(next_permutation(v.begin(), v.end()));
    for(auto i : p) {
        for(auto j : i) cout << j << ' ';
        cout << '\n';
    }
    
    return 0;
}