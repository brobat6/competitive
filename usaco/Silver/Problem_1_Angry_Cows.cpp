// http://usaco.org/index.php?page=viewproblem2&cpid=594

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 50000

int n, k;
int arr[MAXN];

bool check(int x) {
    int cows = 1;
    // max cows allowed = k. For every cow used, cows +=1. return (cows <= k)
    int temp = arr[0];
    int i = 0;
    while(i<n) {
        ++i;
        if((arr[i]-temp)>(2*x)) {
            cows += 1;
            temp = arr[i];
        }
    }
    // cout << "For x = " << x << " the cows needed are " << cows << endl;
    return (cows<=k);
}

int search() {
    int pos = 0, max = 1E9;
    for(int a = max; a>=1; a/=2) while(!check(pos+a)) pos += a;
    return (pos+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    freopen("angry.in","r",stdin);
    freopen("angry.out","w",stdout);
    cin >> n >> k;
    forn(i, n) cin >> arr[i];
    sort(arr, arr+n);
    cout << search();
    return 0;
}
