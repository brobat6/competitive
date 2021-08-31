// http://www.usaco.org/index.php?page=viewproblem2&cpid=788

#include <bits/stdc++.h>

using namespace std;

int n, x;
vector <pair <int, int>> arr[5001];
vector <int> visited[5001];

void dfs(int k, int node) {
    if(visited[node][0]==0) {
        visited[node][0] = 1;
    }
    for(auto next: arr[node]) {
        if(next.second<k) {
            visited[next.first][0] = -1;
        }
        else if(visited[next.first][0]==0) {
            dfs(k,next.first);
        }
    }
}

int func(int k, int v) {
    for(int i=0; i<5001; i++) visited[i][0]=0;
    dfs(k,v);
    int temp = 0;
    for(int i=0; i<5001; i++) {
        if(visited[i][0]==1) temp++;
    }
    return temp-1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    freopen("mootube.in","r",stdin);
    freopen("mootube.out","w",stdout);
    for(int i=0; i<5001; i++) visited[i].push_back(0);
    cin >> n >> x;
    int p, q, r, k, v;
    for(int i=1; i<n; i++) {
        cin >> p >> q >> r;
        arr[p].push_back({q,r});
        arr[q].push_back({p,r});
    }
    for(int i=0; i<x; i++) {
        cin >> k >> v;
        cout << func(k,v) << endl;
    }
    return 0;
}
