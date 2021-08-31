// http://usaco.org/index.php?page=viewproblem2&cpid=939

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("buckets.in","r",stdin);
    // freopen("buckets.out","w",stdout);
    char k;
    int b,l,r;
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            cin >> k;
            if(k=='B') b = (10*i)+j;
            if(k=='R') r = (10*i)+j;
            if(k=='L') l = (10*i)+j;
        }
    }
    // Leaving problem because code is easy but lengthy.
    return 0;
}
