// http://usaco.org/index.php?page=viewproblem2&cpid=987

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    freopen("word.in","r",stdin);
    freopen("word.out","w",stdout);
    int n,k;
    cin >> n >> k;
    string arr[n];
    int l[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        l[i] = arr[i].length();
    }
    int temp = 0;
    for(int i=0; i<n; i++) {
        temp += l[i];
        if(temp>k) {
            temp = l[i];
            cout << endl;
            cout << arr[i];
        }
        else {
            if(i==0) {
                cout << arr[i];
            }
            else {
                cout << " " << arr[i];             
            }
        }
    }
    return 0;
}
