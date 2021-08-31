// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=661&page=show_problem&problem=1998

#include <bits/stdc++.h>

using namespace std;

int n;

int binarySearch(int arr[],int target) {
    int left = 0, right = n-1;
    while (left <= right) {
        int mid = (left + right)/2;
        if(arr[mid]==target) {
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    while(cin >> n) {
        vector <int> ans;
        int arr[n];
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        int m;
        cin >> m;
        sort(arr,arr+n);
        for(int i=0; i<n; i++) {
            cout << arr[i] << " ";
            if(arr[i]>(m/2)) {
                break;
            }
            int dummy = binarySearch(arr,arr[i]);
            cout << dummy << endl;
            if(dummy==-1) {
                continue;
            }
            ans.push_back(arr[i]);
        }
        // for(auto &it : ans) {
            // cout << it << endl;
        // }
    }
    return 0;
}
