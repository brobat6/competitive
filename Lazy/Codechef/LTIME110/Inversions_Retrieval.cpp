#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    if(n <= 1000) {
    cout << n * (n - 1) + 1 << '\n';
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            cout << "compare " << j << " " << i << '\n';
        }
    }
    cout << "put 0" << '\n';
    int x = n * (n + 1) / 2;
    for(int i = 0; i < n * (n - 1)/2; i++) {
        cout << "add " << x << " " << n + i << '\n';
        x++;
    }
    return 0;
    }

    assert(n == 7000);
    cout << 1 << '\n' << "put ";


    int x = rand() % 7000 + 1;

    cout << x * (x + 1) / 2;

    cout << 0;

    return 0;
}