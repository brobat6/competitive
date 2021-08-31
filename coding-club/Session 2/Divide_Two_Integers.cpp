// https://leetcode.com/problems/divide-two-integers/

#include <bits/stdc++.h>

using namespace std;

int D,d;

bool check(long long k, long long n) {
    int sum;
    for (int i=0; i<k; i++) {
        sum += d;
    }
    return (sum <= D);
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
    cin >> D >> d;
    int ans;
    if(D==0) {
        cout << 0;
    }
    else if(D==d) {
        cout << 1;
    }
    else if ((D>0&&d>0)) {
        ans = binary(0,D,D);
        cout << ans+1;
    }
    else if ((D<0&&d<0)) {
        D *= -1;
        d *= -1;
        ans = binary(0,D,D);
        cout << ans+1;
    }
    else if ((D<0&&d>0)) {
        D *= -1;
        ans = binary(0,D,D);
        ans *= -1;
        cout << ans-1;
    }
    else {
        d *= -1;
        ans = binary(0,D,D);
        ans *= -1;
        cout << ans-1;
    }
    return 0;
}
