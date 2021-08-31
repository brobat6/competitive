// http://usaco.org/index.php?page=viewproblem2&cpid=572

#include <bits/stdc++.h>
#define forn(i, a, n) for (int i = a; i < int(n); i++)
using namespace std;

struct Store {
    int x;
    int y;
    int z;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    freopen("bcount.in","r",stdin);
    freopen("bcount.out","w",stdout);
    int n, q;
    cin >> n >> q;
    int breed[n];
    forn(i,0,n) cin >> breed[i];
    Store s[n];
    forn(i, 0, n) {
        s[i].x = 0;
        s[i].y = 0;
        s[i].z = 0;
    } 
    if(breed[0]==1) s[0].x = 1;
    if(breed[0]==2) s[0].y = 1;
    if(breed[0]==3) s[0].z = 1;
    forn(i,1,n) {
        if(breed[i]==1) {
            s[i].x += s[i-1].x + 1;
            s[i].y = s[i-1].y;
            s[i].z = s[i-1].z;
        }
        if(breed[i]==2) {
            s[i].y += s[i-1].y + 1;
            s[i].x = s[i-1].x;
            s[i].z = s[i-1].z;
        }
        if(breed[i]==3) {
            s[i].z += s[i-1].z + 1;
            s[i].y = s[i-1].y;
            s[i].x = s[i-1].x;
        }
    }
    // Now s[i] = {x,y,z}, the prefix sums.
    int a, b;
    forn(i,0,q) {
        cin >> a >> b;
        --a; --b;
        if(a==0) {
            cout << s[b].x << " " << s[b].y << " " << s[b].z << endl;
        }
        else {
            --a;
            cout << (s[b].x-s[a].x) << " " << (s[b].y-s[a].y) << " " << (s[b].z-s[a].z) << endl;
        }
    }
    return 0;
}
