// http://usaco.org/index.php?page=viewproblem2&cpid=1011

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    freopen("triangles.in","r",stdin);
    freopen("triangles.out","w",stdout);
    int n;
    cin >> n;
    int arr[n][2];
    for(int i=0; i<n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    priority_queue <int> pq;
    int area = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                if(((i==j)||(j==k))||(i==k)) {
                    continue;
                }
                else {
                    if ((arr[i][0]==arr[j][0])&&(arr[j][1]==arr[k][1])) {
                        area = abs(arr[i][1]-arr[j][1])*abs(arr[j][0]-arr[k][0]);
                        pq.push(area);
                    }
                }
            }
        }
    }
    cout << pq.top();
    return 0;
}
