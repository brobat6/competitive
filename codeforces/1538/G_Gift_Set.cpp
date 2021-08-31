//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 200100
#define MOD 1000000007

int x, y, a, b;

bool check(long long k) {
    // Return true if x gifts can be made
    // Return false if x gifts cannot be made
    float temp[2];
    if(b==a) return (b*k <= y);
    temp[0] = float(b*k - x)/(b - a);
    temp[1] = float(y - a*k)/(b - a);
    // cout << "y" << endl;
    int bow = ceil(temp[0]);
    int targ = floor(temp[1]);
    if(bow<targ) return false;
    if(temp>=0) return true;
    if(targ<=k) return true;
    return false;
}

long long binarySearch(){
    long long pos = 0; long long mx = (x+y)/(a+b);
    for(long long a = mx; a >= 1; a /= 2){
        while(check(pos+a)) pos += a;
    }
    return pos;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    cin >> t;
while(t--) {
    cin >> x >> y >> a >> b;
    if(x>y) swap(x, y);
    if(a>b) swap(a, b);
    cout << binarySearch() << endl;
}
    return 0;
}

