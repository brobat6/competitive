// https://www.hackerearth.com/practice/algorithms/sorting/quick-sort/practice-problems/algorithm/noor-and-his-pond-760eabe0/

#include <iostream>
#include <set>
#include <algorithm>
#include <array>

using namespace std;

int func() {
    int n,m = 0;
    cin >> n;
    int s,e;
    multiset <int> ms;
    array <int,2> arr[n];
    multiset <int>::iterator it;
    for (int i=0;i<n;i++) {
        scanf("%d %d",&arr[i][1],&arr[i][0]);
    }
    sort(arr,arr+n);
    for (int i=0;i<n;i++) {
        ms.insert(arr[i][1]);
        it = ms.upper_bound(arr[i][0]);
        ms.erase(ms.begin(),it);
        if (ms.size()>m) {
            m = ms.size();
        }        
    }
    cout << m << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i=1;i<=t;i++) {
        func();
    }
}