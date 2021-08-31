// https://codeforces.com/contest/1501/problem/C

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 200000

int n;
int arr[MAXN], grr[MAXN];
int ans[4];

bool twosum(int x) {
    int l = 0, r = n-1;
    int k = 0;
    while(l<r) {
        if(arr[l]+arr[r]==x) {
            k += 1;
            if(k==1) {
                ans[0] = arr[l];
                ans[1] = arr[r];
            }
            if(k==2) {
                ans[2] = arr[l];
                ans[3] = arr[r];
                return true;   
            }
            r--;
            l++;
        }
        else if(arr[l]+arr[r]<x) {
            l++;
        } else {
            r--;
        }
    }
    return false;
}

int search() {
    int pos = 0;
    int max = arr[n-1] + arr[n-2] + 1;
    for(int a = max; a>=1; a/=2) {
        if(twosum(a)) {
            cout << "YES" << endl;
            forn(i, 4) {
                forn(j, n) {
                    if(grr[j]==ans[i]) {
                        cout << (j+1) << " ";
                        grr[j] = -1;
                        break;
                    }
                }
            }
            
    
        return 1;
        }

}
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    cin >> n;
    forn(i, n) cin >> arr[i];
    forn(i, n) grr[i] = arr[i];
    sort(arr,arr+n);
    int z = arr[n-1]+arr[n-2]+1;
    if(search()==0) cout << "NO";
    return 0;
}
