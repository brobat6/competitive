#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    freopen("shuffle.in","r",stdin);
    freopen("shuffle.out","w",stdout);
    int n;
    cin >> n;
    int a[n+1],b[n+1],c[n+1];
    a[0] = 0;
    b[0] = 0;
    c[0] = 0;
    for (int i=1 ; i<=n ; i++) {
        cin >> a[i];
    }
    for (int i=1 ; i<=n ; i++) {
        cin >> b[i];
    }
    for (int i=1 ; i<=n ; i++) {
        c[i] = b[a[a[a[i]]]];
    }        
    for (int i=1 ; i<=n ; i++) {
        cout << c[i] << endl;
    }
}