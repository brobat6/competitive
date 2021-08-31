// http://www.usaco.org/index.php?page=viewproblem2&cpid=988

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    freopen("photo.in","r",stdin);
    freopen("photo.out","w",stdout);
    int n;
    cin >> n;
    int b[n] = {0};
    for(int i=1;i<n;i++) {
        cin >> b[i];
    } 
    int control = 1;
    int a[n];
    for (a[0]=1;a[0]<b[1];a[0]++) {
        control = 1;
        for (int i=1;i<n;i++) {
            a[i] = b[i] - a[i-1];
            if(a[i]<1) {
                control = 0;
                break;
            }
            for(int j=0;j<i;j++) {
                if(a[j]==a[i]) {
                    control = 0;
                    break;
                }
            }
        }
        if(control==1) {
            break;
        }
    }
    for(int i=0;i<n-1;i++) {
        cout << a[i] << " ";
    }
    cout << a[n-1];
    return 0;
}

/* 
Can also be done in O(N) time. Final equation is = sum of a[i] = n(n+1)/2
Add all b[i] and subtract sum of a[i] to get sum of extreme values of a.
*/
