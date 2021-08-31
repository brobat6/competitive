// http://www.usaco.org/index.php?page=viewproblem2&cpid=991

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;

long long n, m, k;

long long find(long long g) {
    if((n-g)%k==0) return ((n-g)/k);
    else return (((n-g)/k)+1);
}

bool check(long long x) {
    long long days = 0;
    long long g = 0;
    if((n/x)<=k) {
        days = find(g);
    }
    else {
        while(true) {
            g += (n-g)/x;
            days += 1;
            if(g>=(n-(k*x))) {
                days += find(g);
                break;
            }
        }
    }
    return (days<=k);
}

long long search() {
    long long pos = 0, max = 1E12;
    for(long long a = max; a>=1; a/=2) {
        while(check(pos+a)) pos+= a;
    }
    return pos;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    freopen("loan.in","r",stdin);
    freopen("loan.out","w",stdout);
    cin >> n >> k >> m;
    cout << search();
    return 0;
}
