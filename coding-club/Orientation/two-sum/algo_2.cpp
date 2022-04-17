#include <bits/stdc++.h>
using namespace std;

// Second approach - Two Pointers Method.

int main() {

    int length, sum;
    cin >> length >> sum;
    int arr[length];
    for(int i = 0; i < length; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + length);

    int left = 0;
    int right = length - 1;

    while(left < right) {
        if(arr[left] + arr[right] > sum) {
            right--;
        }
        else if(arr[left] + arr[right] < sum) {
            left++;
        }
        else {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}