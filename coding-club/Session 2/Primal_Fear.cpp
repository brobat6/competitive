// https://www.spoj.com/problems/VECTAR8/

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

int isPrime(int z, vector <int>& nums) {
    int n = z;
    int count = 0;
    while(n!=0) {
        n /= 10;
        count += 1;
    }
    if(count==1) {
        return true;
    }
    int mul = 1;
    for(int i=1; i<count; i++) {
        mul *= 10;
    }
    int t = z % mul;
    int x = binarySearch(nums,t);
    if(x==-1) {
        return false;
    }
    else {
        return true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int n = 1000000;
    int arr[n+1];
    for(int i=0; i<=n; i++) {
        arr[i]=0;
    }
    for(int i=0; i<10; i++) {
        cout << arr[i] << " ";
    }    
    vector <int> primes;
    for(int i=2; i<=n; i++) {
        if(arr[i]==0) {
            arr[i] = 1;
            primes.push_back(i);
            for(int j=i; j<=n; j+=i) {
                arr[j] = 1;
            }
        }
    }
    // for(int i=0; i<10; i++) {
        // cout << primes[i] << " ";
    // }
    // Now the vector "primes" gives all the prime numbers from 2 to 1000000.
    vector <int> op;
    for(auto& it : primes) {
        if(isPrime(it,op)) {
            op.push_back(it);
        }
    }
    // Now all the good primes should be stored in vector op.
    // int T;
    // cin >> T;
    // while(T--) {
    //     int N;
    //     cin >> N;
    //     int c = 0;
    //     for(auto& it:op) {
    //         if(it>N) {
    //             break;
    //         }
    //         c += 1; 
    //     }
    //     cout << c << endl;
    // }
    return 0;
}
