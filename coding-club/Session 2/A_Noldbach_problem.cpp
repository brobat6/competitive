// https://codeforces.com/problemset/problem/17/A

#include <bits/stdc++.h>

using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int n,k;
    cin >> n;
    cin >> k;
    int arr[n+1];
    vector <int> v;
    int primes[1000];
    for(int i=0; i<=n; i++) {
        arr[i] = 0;
    }
    for(int i=2; i<=n; i++) {
        for(int j=i*i; j<=n; j+=i) {
            arr[j-1] = 1;
        }
    }
    for(int i=0; i<=n; i++) {
        if(arr[i-1]==0) {
            v.push_back(i);
        }
    }
    v.erase(v.begin());
    int s = v.size();
    int* a = &v[0];
    // array a now holds {1,2,3,5,7.....}
    int b[s-2];
    for(int i=0; i<(s-2); i++) {
        b[i] = a[i+1]+a[i+2];
    }
    int t = s-2;
    int count = 0;
    for(int i=0; i<t; i++) {
        if(b[i]<n
    }
    if(count>=k) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}
