#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n = 1E6;
    int arr[n];
    for(int i = 0; i < n; i++) {
        arr[i] = i;
    }
    long long x = 0;
    for(int i = 0; i < n; i++) {
        x += arr[i];
    }
    cout << x;
    
    return 0;
}