#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {

}

#define pi pair<int, int>

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int h, w, n;
    cin >> h >> w >> n;
    map<int, set<int>> x, y;
    int sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        x[a].insert(b);
        y[b].insert(a);
    }
    map<pi, int> dist;
    queue <pi> q;
    dist[{sx, sy}] = 0;
    q.push({sx, sy});
    while(!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        // Check the 4 cardinal directions from {a, b}
        // First, check values nearest to b in x[a]
        if(x[a].size() != 0) {
            auto temp = x[a].upper_bound(b);
            if(temp != x[a].end()) {
                if(dist.find({a, (*temp) - 1}) == dist.end()) {
                    dist[{a, (*temp) - 1}] = dist[{a, b}] + 1;
                    q.push({a, (*temp) - 1});
                }
            }
            if(temp != x[a].begin()) {
                --temp;
                if(dist.find({a, (*temp) + 1}) == dist.end()) {
                    dist[{a, (*temp) + 1}] = dist[{a, b}] + 1;
                    q.push({a, (*temp) + 1});
                }
            }   
        }
        if(y[b].size() != 0) {
            auto temp = y[b].upper_bound(a);
            if(temp != y[b].end()) {
                if(dist.find({(*temp) - 1, b}) == dist.end()) {
                    dist[{(*temp) - 1, b}] = dist[{a, b}] + 1;
                    q.push({(*temp) - 1, b});
                }
            }
            if(temp != y[b].begin()) {
                --temp;
                // cout << (*temp) << endl;
                if(dist.find({(*temp) + 1, b}) == dist.end()) {
                    dist[{(*temp) + 1, b}] = dist[{a, b}] + 1;
                    q.push({(*temp) + 1, b});
                }
            }
        }
    }
    if(dist.find({gx, gy}) == dist.end()) {
        cout << -1;
    } else {
        cout << dist[{gx, gy}];
    }
    
    return 0;
}