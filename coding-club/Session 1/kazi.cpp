// https://www.codechef.com/problems/SPIT1

#include <iostream>
#include <map>

using namespace std;

int main() {
    map <string,int> m;
    int n;
    cin >> n;
    int maxVal = 0, v;
    string s, maxName;
    for (int i=1; i<=n; i++) {
        cin >> s;
        cin >> v;
        m[s] += v;
        if (m[s] > maxVal) {
            maxVal = m[s];
            maxName = s;
        }
    }
    cout << maxName;
    return 0;
}