#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
using namespace std;

int main() {
    freopen("cbarn.in","r",stdin);
    freopen("cbarn.out","w",stdout);
    int n;
    cin >> n;
    int a[n];
    set <int> s;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int sum;
    for (int i=0 ; i<n ; i++) {
        sum = 0;
        for (int j=0 ; j<n ; j++) {
            sum += j * a[j];
        }
        s.insert(sum);
        int temp = a[0];
        for (int j=1 ; j<n ; j++) {
            a[j-1] = a[j];
        }
        a[n-1] = temp;
    }
    cout << *s.begin();
}