// https://www.hackerrank.com/challenges/sock-merchant/problem

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    int count = 0, pairs = 0;
    sort(arr,arr+n);
    for(int i=0; i<n; i++) {
        int j = arr[i];
        count = 1;
        for (int k=(i+1);k<n;k++) {
            if (arr[k]==j) {
                count +=1;
                i++;
            }
            else {
                break;
            }
        }
        if(count%2==0) {
            pairs += count/2;
        }
        else {
            pairs += (count-1)/2;
        }
    }
    cout << pairs;
    return 0;
}
