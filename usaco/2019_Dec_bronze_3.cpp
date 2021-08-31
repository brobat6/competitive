// http://usaco.org/index.php?page=viewproblem2&cpid=963

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int k,n;
    cin >> k >> n;
    int arr[k][n];
    for(int i=0;i<k;i++) {
        for(int j=0;j<n;j++) {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            int count = 0;
            for(int r=0;r<k;r++) {
                if(arr[k][i]<arr[k][j]) {
                    count += 1;
                }
                else {
                    break;
                }
            }
            if(count==k) {
                cout << i << " " << j << endl;
                ans += 1;
            }
        }
    }
    cout << ans;
    return 0;
}
