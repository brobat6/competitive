#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> choc(n);
    for(int i = 0; i < n; i++) {
        cin >> choc[i].first;
    }
    for(int i = 0; i < n; i++) {
        cin >> choc[i].second;
    }
    sort(choc.begin(), choc.end(), [&](pair<int, int> a, pair<int, int> b) {
        if(a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    });
    vector<pair<int, int>> box(m);
    for(int i = 0; i < m; i++) {
        cin >> box[i].first;
    }
    for(int i = 0; i < m; i++) {
        cin >> box[i].second;
    }
    sort(box.begin(), box.end(), [&](pair<int, int> a, pair<int, int> b) {
        if(a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    });
    multiset <int> ms;
    int j = 0;
    int i = 0;
    while(i < n) {
        if(j >= m) {
            if(ms.empty()) {
                cout << "No";
                return 0;
            }
            auto x = ms.lower_bound(choc[i].second);
            if(x == ms.end()) {
                cout << "No";
                return 0;
            }
            ms.erase(x);
            i++;
            continue;
        }
        if(box[j].first >= choc[i].first) {
            ms.insert(box[j].second);
            j++;
            continue;
        }
        if(ms.empty()) {
            cout << "No";
            return 0;
        }
        auto x = ms.lower_bound(choc[i].second);
        if(x == ms.end()) {
            cout << "No";
            return 0;
        }
        ms.erase(x);
        i++;
    }
    cout << "Yes";
    return 0;
}