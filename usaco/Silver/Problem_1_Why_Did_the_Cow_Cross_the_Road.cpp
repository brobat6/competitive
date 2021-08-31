// http://www.usaco.org/index.php?page=viewproblem2&cpid=714

#include <bits/stdc++.h>

using namespace std;

struct Cow {
    long long x;
    long long y;
};

bool comp(Cow a, Cow b) {
    if(a.y==b.y) return a.x < b.x;
    return a.y < b.y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("helpcross.in","r",stdin);
    // freopen("helpcross.out","w",stdout);
    int c, n;
    cin >> c >> n;
    long long a[c];
    for(int i=0; i<c; i++) cin >> a[i];
    sort(a,a+c);
    Cow b[n];
    for(int i=0; i<n; i++) cin >> b[i].x >> b[i].y;
    sort(b,b+n,comp);
    int count = 0;
    int i = 0;
    
    cout << count;
    return 0;
}
