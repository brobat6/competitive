#include <cstdio>
#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main() {
    freopen("cowqueue.in","r",stdin);
    freopen("cowqueue.out","w",stdout);
    int n;
    cin >> n;
    array <int,2> arr[n];
    for (int i=0 ; i<n ; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    sort(arr,arr+n);
    int freetime,extratime=0;
    for(int i=1; i<n ; i++) {
        freetime = arr[i][0]-arr[i-1][0];
        if (extratime < 0) {
            extratime = 0;
        }
        extratime += arr[i-1][1] - freetime;
    }
    if (extratime < 0) {
        extratime = 0;
    }
    int time = arr[n-1][0] + arr[n-1][1] + extratime;
    cout << time;
    return 0;
}