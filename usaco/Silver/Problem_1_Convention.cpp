// http://www.usaco.org/index.php?page=viewproblem2&cpid=858

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 100000

int n, m, c;
long long max_ans;
int arr[MAXN];

bool check(int x) {
    int skipped = 0;
    int temp = arr[0], temp_num = 0;
    int i = 0;
    while(i<n) {
        ++i;
        if((i-temp_num)>=c) {
            temp = arr[i];
            temp_num = i;
            continue;
        }
        if((arr[i]-temp)>x) {
            skipped += c - (i - temp_num);
            temp = arr[i];
            temp_num = i;
            continue;
        }
    }
    // cout << "For answer " << x << " skipped = " << skipped << endl;
    return (skipped<=max_ans);
}

int search() {
    int pos = 0;
    int max = 1000000000;
    for(int a = max; a>=1; a/=2) {
        while(!check(pos+a)) {
            pos += a;
        }
    }
    return (pos+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    freopen("convention.in","r",stdin);
    freopen("convention.out","w",stdout);
    cin >> n >> m >> c;
    forn(i, n) cin >> arr[i];
    max_ans = (m*c)-n;
    sort(arr, arr+n);
    // forn(i, n) cout << arr[i] << " ";
    // cout << max_ans << endl;
    cout << search();
    return 0;
}
