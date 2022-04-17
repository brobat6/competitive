#include <bits/stdc++.h>
using namespace std;

// First approach - check all pairs of values in the array.

int main() {

    int length, sum;
    cin >> length >> sum;
    int arr[length];
    for(int i = 0; i < length; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < length; i++) {
        for(int j = i + 1; j < length; j++) {
            if(arr[i] + arr[j] == sum) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}