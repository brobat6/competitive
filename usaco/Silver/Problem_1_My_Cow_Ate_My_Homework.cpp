// http://www.usaco.org/index.php?page=viewproblem2&cpid=762

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    freopen("homework.in","r",stdin);
    freopen("homework.out","w",stdout);
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    int temp;
    int min[n];
    min[n-1] = arr[n-1];
    int sum[n];
    sum[n-1] = arr[n-1];
    for(int i=(n-2); i>=0; i--) {
        sum[i] = sum[i+1] + arr[i];
        if(arr[i]<min[i+1]) {
            min[i] = arr[i];
        } else  {
            min[i] = min[i+1];
        }
    }
    // for(int i=0; i<n; i++) {
    //     cout << (sum[i]-min[i]) << endl;
    // }
    float avg[n];
    for(int i=0; i<n; i++) {
        avg[i] = (sum[i]-min[i])/float((n-i-1));
    }
    // for(int i=0; i<n; i++) {
    //     cout << avg[i] << endl;
    // }
    avg[0] = 0;
    avg[n-1] = 0;
    float max = 0, dummy;
    for(int i=0; i<n; i++) {
        if(avg[i]>max) {
            max = avg[i];
        }
    }

    for(int i=0; i<(n-1); i++) {
        if(avg[i]==max) {
            cout << i << endl;
        }
    }
    return 0;
}
