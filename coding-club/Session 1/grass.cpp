#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int n,l,w;
    cin >> n >> l >> w;
    array <double,2> arr[n];
    double temp1,temp2;
    for (int i=0;i<n;i++) {
        scanf("%d %d",&temp1,&temp2);
        if (temp2>(w/2)) {
            temp2 = sqrt((temp2*temp2)-(w*w/4));
            arr[i][0] = temp1-temp2;
            arr[i][1] = temp1+temp2;
        }
    }
    sort(arr,arr+n);
    // [-1,3][2,8][3,5][5,9][8,12][10,16][14,18][15,23]
    for (int i=0;i<n;i++) {
        // cout << "[" << arr[i][0] << "," << arr[i][1] << "] ";
    }
}