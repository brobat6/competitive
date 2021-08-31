// http://www.usaco.org/index.php?page=viewproblem2&cpid=668

#include <bits/stdc++.h>

using namespace std;

int n, temp;
vector <int> v[200];
bool visited[200];

struct Store {
    int x;
    int y;
    int z;
};

void dfs(int node) {
    visited[node] = true;
    temp++;
    for(int next : v[node]) {
        if(!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    freopen("moocast.in","r",stdin);
    freopen("moocast.out","w",stdout);
    cin >> n;
    Store s[n];
    for(int i=0; i<n; i++) {
        cin >> s[i].x >> s[i].y >> s[i].z;
    }
    int radius, dist;
    // Now the cows are stored in struct. We have to make adjacency list (v).
    for(int i=0; i<n; i++) {
        radius = (s[i].z)*(s[i].z);
        for(int j=0; j<n; j++) {
            if(i==j) continue;
            dist = ((s[i].x-s[j].x)*(s[i].x-s[j].x))+((s[i].y-s[j].y)*(s[i].y-s[j].y));
            if(dist<=radius) {
                v[i].push_back(j);
            }
        }
    }
    int max = 0;
    // Now the adjacency list has been created. We will run DFS for every single node (0 to n-1) and give max answer.
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) visited[j] = false;
        temp = 0;
        dfs(i);
        if(temp>max) {
            max = temp;
        }
    }
    cout << max;
    return 0;
}
