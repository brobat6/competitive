// http://usaco.org/index.php?page=viewproblem2&cpid=571

#include <bits/stdc++.h>

using namespace std;

bool comp(int a, int b) {
    return a > b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    freopen("highcard.in","r",stdin);
    freopen("highcard.out","w",stdout);
    int n, temp;
    cin >> n;
    int a[(2*n)+1],b[n+1];
    a[0] = 0;
    b[0] = 0;
    for(int i=1; i<=(2*n); i++) a[i] = i;
    for(int i=1; i<=n; i++) {
        cin >> temp;
        b[i] = temp;
        a[temp] = 0;
    }
    sort(a,a+((2*n)+1),comp);
    sort(b,b+(n+1),comp);
    // for(int i=0; i<n; i++) {
        // cout << a[i] << " " << b[i] << endl;
    // }
    int i=0, count = 0;
    for(int j=0; j<n; j++) {
        if(i>=n) break;
        while(b[i]>a[j]) i++;
        count++;
        i++;
    }
    cout << count;
    return 0;
}
