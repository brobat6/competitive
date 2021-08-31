//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 5020
#define MOD 1000000007

int n;
int arr[MAXN];
int brr[MAXN];
int a[MAXN];
int grr[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int k = 0;
    int ans = 0;
    int bns = 0;
    cin >> n;
    forn(i, n) {
        cin >> arr[i];
        if(arr[i]==1) {
            k += 1;
            grr[k] = i;
        }
        a[i] = arr[i];
        brr[i] = arr[i];
    }
    // for(int i=1; i<=k; i++) cout << grr[i] << " ";
    // cout << endl;
    if(k==0) {
        cout << 0;
        return 0;
    }
    for(int i=1; i<=k; i++) {
        if(i%2==0) {
            int temp = grr[k + 1 - (i/2)];
            for(int j=1; j<=n; j++) {
                if((temp+j)<n) {
                    if(arr[temp+j]==0) {
                        ans += j;
                        arr[temp+j] = 1;
                        break;
                    }
                }
                if((temp-j)>=0) {
                    if(arr[temp-j]==0) {
                        ans += j;
                        arr[temp-j] = 1;
                        break;
                    }
                }
            }
        }
        else {
            int temp = grr[(i+1)/2];
            for(int j=1; j<=n; j++) {
                if((temp-j)>=0) {
                    if(arr[temp-j]==0) {
                        ans += j;
                        arr[temp-j] = 1;
                        break;
                    }
                }
                if((temp+j)<n) {
                    if(arr[temp+j]==0) {
                        ans += j;
                        arr[temp+j] = 1;
                        break;
                    }
                }
            }
        }
    }
    for(int i=1; i<=k; i++) {
        if(i%2==1) {
            int temp = grr[k -((i-1)/2)];
            // cout << temp << endl;
            for(int j=1; j<=n; j++) {
                if((temp+j)<n) {
                    if(brr[temp+j]==0) {
                        bns += j;
                        brr[temp+j] = 1;
                        break;
                    }
                }
                if((temp-j)>=0) {
                    if(brr[temp-j]==0) {
                        bns += j;
                        brr[temp-j] = 1;
                        break;
                    }
                }
            }
        }
        else {
            int temp = grr[i/2];
            // cout << temp << endl;
            for(int j=1; j<=n; j++) {
                if((temp-j)>=0) {
                    if(brr[temp-j]==0) {
                        bns += j;
                        brr[temp-j] = 1;
                        break;
                    }
                }
                if((temp+j)<n) {
                    if(brr[temp+j]==0) {
                        bns += j;
                        brr[temp+j] = 1;
                        break;
                    }
                }
            }
        }
    }
    cout << min(ans, bns) << endl;
    return 0;
}
