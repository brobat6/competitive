#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    // assert a and b are in the limits.
    if(a < 0 || a > 1000 || b < 0 || b > 1000) {
        cout << "Input values are not in range!";
        getchar(); getchar();
        return 0;
    }
    cout << a + b;
    getchar(); getchar();
    return 0;
}