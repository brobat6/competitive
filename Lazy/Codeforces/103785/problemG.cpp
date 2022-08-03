#include <bits/stdc++.h>
using namespace std;
#define int long long

bool comp(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, function<bool(pair<int, int>, pair<int, int>)>> p(comp);
    for(int i = 0; i < n; i++) {
        pair<int, int> x;
        cin >> x.first;
        x.second = i + 1;
        p.push(x);
    }
    assert(n != 1);
    auto x = p.top();
    p.pop();
    auto y = p.top();
    p.push(x);
    if(x.first - y.first > 1) {
        cout << -1;
        return 0;
    }
    vector <int> ans;
    while(!p.empty()) {
        auto x = p.top();
        p.pop();
        ans.push_back(x.second);
        x.first--;
        if(x.first > 0) {
            p.push(x);
        }
    }
    for(auto i : ans) cout << i << " ";
    
    return 0;
}