// Template

#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector <int>& nums,int target) {
    int left = 0, right = nums.size()-1;
    while (left <= right) {
        int mid = (left + right)/2;
        if(nums[mid]==target) {
            return mid;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

bool check(long long k, long long n) {
    //return true if yes
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

    return 0;
}
