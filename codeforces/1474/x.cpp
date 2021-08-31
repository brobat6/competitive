#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int z=1;z<=t;z++) {
        int n;
        scanf("%d",&n);
        int nn = 2*n;
        vector <int> v[nn];
        for (int y=0;y<(2*n);y++) {
            scanf("%d",&v[y]);
        }
        sort(v.begin(),v.end());
        int x;
        int val = 0;
        for (int i=0;i<nn;i++) {
            x = v[nn-1] + v[i];
        }
    }
}