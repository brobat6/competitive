#include <iostream>
#include <tuple>
using namespace std;

int gcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

int main() {
    int a = 14, b = 19, c = 143;
    int x, y;
    int g = gcd(a, b, x, y);
    if(c%g) cout << "No solution" << endl;
    else {
        x = x * c / g;
        y = y * c / g;
        cout << "Principal solution of the given equation is - \n";
        printf("%d.%d + %d.%d = %d\n", a, x, b, y, c);
    }
    cout << "5 more solutions of the given equation are - \n";
    int k = 1;
    while(k<=5) {
        x = x + b/g;
        y = y - a/g;
        k++;
        printf("%d.%d + %d.%d = %d\n", a, x, b, y, c);
    }
}