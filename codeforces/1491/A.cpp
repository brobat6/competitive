// https://codeforces.com/contest/1491/problem/A

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int n,q,count=0;
    cin >> n >> q;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        if(arr[i]==1) {
            count++;
        }
    }
    int t,x,k;
    for(int i=0; i<q; i++) {
        cin >> t;
        if(t==2) {
            cin >> k;
            if(k<=count) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            } 
        }
        if(t==1) {
            cin >> x;
            arr[x-1] = 1 - arr[x-1];
            if(arr[x-1]==0) {
                count--;
            }
            else {
                count++;
            }
        }
    }
    return 0;
}
