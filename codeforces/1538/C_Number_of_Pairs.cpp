//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 200100
#define MOD 1000000007

int n, l, r;
int ans;
int arr[MAXN];

bool c1(int x, int test) {
    if(arr[test] + arr[x] < r) return true;
    else return false;
}

bool c2(int x, int test) {
    if(arr[test] + arr[x] > l) return true;
    else return false;
}


int f1(int test) {
    int pos = 0; int mx = n-1;
    for(int a = mx; a>=1; a/=2) {
        while(c1(pos+a, test)) pos+=a;
    }
    return pos;
}

int f2(int test) {
        int pos = 0; int mx = n-1;
    for(int a = mx; a>=1; a/=2) {
        while(!c2(pos+a, test)) pos+=a;
    }
    return pos+1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
//     int t;
//     cin >> t;
// while(t--) {
//     ans = 0;
//     cin >> n >> l >> r;
//     forn(i, n) cin >> arr[i];
//     sort(arr, arr+n);
//     forn(i, n) {
//         cout << f1(i) << " " << f2(i) << endl;
//     }
// }
    int a = 7;
    int b = 3;
    long double c = a/float(b);
    cout << c << endl;
    return 0;
}

