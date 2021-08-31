// http://usaco.org/index.php?page=viewproblem2&cpid=591

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    freopen("promote.in","r",stdin);
    freopen("promote.out","w",stdout);
    int bi,bf,si,sf,gi,gf,pi,pf;
    cin >> bi >> bf >> si >> sf >> gi >> gf >> pi >> pf;
    int x,y,z,w;
    z = pf-pi;
    y = gf+z-gi;
    x = y+sf-si;
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
    return 0;
}
