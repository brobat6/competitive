// http://usaco.org/index.php?page=viewproblem2&cpid=1013

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("swap.in","r",stdin);
    // freopen("swap.out","w",stdout);
    int n,k; 
    cin >> n >> k;
    int arr[n];
    int ai,af,bi,bf;
    cin >> ai >> af >> bi >> bf;
    int al = af-ai;
    int bl = bf-bi;
    for(int i=0; i<n; i++) {
        arr[i] = i+1;
    }
    for(int i=0; i<k; i++) {
        int temp[al];
        for(int j=(ai-1); j<af; j++) {
            temp[j-ai+1] = arr[af+ai-2-j];
        }
        
    }
    return 0;
}
