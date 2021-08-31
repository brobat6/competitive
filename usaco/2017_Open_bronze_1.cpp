#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    freopen("lostcow.in","r",stdin);
    freopen("lostcow.out","w",stdout);
    int x,y;
    set <int> a = {1,4,16,64,256,1024};
    set <int> b = {2,8,32,128,512,2048};
    cin >> x >> y;
    int d = y-x;
    if (d>0) {
        int n = *a.lower_bound(d);
        int ans = (2*n) + d - 2;
        cout << ans;
    } else {
        d *= -1;
        int n = *b.lower_bound(d);
        int ans = (2*n) + d - 2;
        cout << ans;
    }
    return 0;
}