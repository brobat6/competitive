// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=625&page=show_problem&problem=3986

#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);            // to redirect cin
    // freopen("output.txt", "w", stdout);     // to redirect cout
    int n;
    cin >> n;
    string personName;
    int dd,mm,yyyy;
    int z;
    map <int,string> m;
    for (int i=1;i<=n;i++) {
        cin >> personName >> dd >> mm >> yyyy;
        z = (yyyy*10000) + (mm*100) + dd;
        m[z] = personName;
    }
    cout << (--m.end())->second << endl;
    cout << m.begin()->second << endl;
}