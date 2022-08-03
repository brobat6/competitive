#include <bits/stdc++.h>
using namespace std;

class X {
public:
    int x;

    X(int y) {
        x = y;
    }
};

X operator +(const X &a, const X &b) {
    return a.x * b.x;
}

int main() {

    X a(3);
    X b(4);

    cout << (a + b).x << '\n';

    return 0;
}