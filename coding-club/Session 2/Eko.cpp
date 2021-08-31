// https://www.spoj.com/problems/EKO/

#include <bits/stdc++.h>

using namespace std;

long long m;
vector <long long> v;

bool check(long long k, long long n) {
    long long sum = 0;
    for(long long i=0; i<n; i++) {
        if (v[i] > k) {
            sum += (v[i] - k);
        } 
    }
    return (sum >= m);
}

long long binary(long long left, long long right, long long n) {
    if (right - left <= 1) {
        if (check(right,n)==1) {
            return right;
        }
        else {
            return left;
        }
    }
    long long mid = (left + right) / 2;
    if (check(mid,n)==1) {
        return binary(mid,right,n);
    }
    else {
        return binary(left,mid-1,n);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    long long n , temp;
    cin >> n >> m;
    for(long long i=0; i<n; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    long long ans = binary(0,1000000,n);
    cout << ans;
    return 0;
}
