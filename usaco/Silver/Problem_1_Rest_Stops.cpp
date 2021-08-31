// http://www.usaco.org/index.php?page=viewproblem2&cpid=810

#include <bits/stdc++.h>

using namespace std;

struct Stops {
    long long x;
    long long t;
};

bool comp(Stops a, Stops b) {
    return a.t > b.t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("reststops.in","r",stdin);
    // freopen("reststops.out","w",stdout);
    long long l,n,rf,rb;
    cin >> l >> n >> rf >> rb;
    Stops arr[n];
    for(long long i=0; i<n; i++) cin >> arr[i].x >> arr[i].t;
    sort(arr, arr+n, comp);
    long long gain = rf-rb;
    long long ans = 0;
    long long c = arr[0].x;
    ans += (arr[0].t*c*gain);
    for(long long i=1; i<n; i++) {
        if(arr[i].x>c) {
            ans += ((arr[i].x-c)*(arr[i].t)*(gain));
            c = arr[i].x;
        }
    }
    cout << ans;
    return 0;
}
