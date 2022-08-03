#include <bits/stdc++.h>
using namespace std;
#define int long long

vector <int> parent;

int find(int x) {
    if(x == parent[x]) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

bool unite(int a, int b) {
    int c = find(a);
    int d = find(b);
    if(c != d) {
        parent[d] = c;
        return true;
    }
    return false;
}

int find_number_of_components(int n) {
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(find(i) == i) {
            ans++;
        }
    }
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    parent.resize(n);
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }

    // code
    
    return 0;
}