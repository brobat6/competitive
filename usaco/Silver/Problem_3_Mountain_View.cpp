// http://www.usaco.org/index.php?page=viewproblem2&cpid=896

#include <bits/stdc++.h>

using namespace std;

struct coordinate {
    long long x;
    long long y;
};  

bool comp(coordinate a, coordinate b) {
    return a.y > b.y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("mountains.in","r",stdin);
    // freopen("mountains.out","w",stdout);
    long long n;
    cin >> n;
    coordinate arr[n];
    for(long long i=0; i<n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }
    sort(arr,arr+n,comp);
    long long mp,mn,tp,tn;
    long long count = 1;
    mp = arr[0].x - arr[0].y;
    mn = arr[0].x + arr[0].y;
    for(long long i=1; i<n; i++) {
        tp = arr[i].x - arr[i].y;
        tn = arr[i].x + arr[i].y;
        if(tp<mp) {
            mp = tp;
            count++;
        }
        if(tn>mn) {
            mn = tn;
            count++;
        }
    }
    cout << count;
    return 0;
}
