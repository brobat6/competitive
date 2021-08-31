#include <iostream>
#include <vector>
using namespace std;

int main() {
    // lp[i] stores the least prime divisor of i. lp[5] = 5, lp[6] = 2, etc.
    // To find prime factorisation of a number i in vector v, v.push_back(lp[i]), i /= lp[i] until 1 is reached.
    // pr stores prime numbers from 2 to N.
    int N = 10000000;
    vector <int> lp(N+1, 0);
    vector<int> pr;
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j=0; j<pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j) lp[i * pr[j]] = pr[j];
    }
    int x = 360;
    while(x!=1) {
        cout << lp[x] << "*";
        x /= lp[x];
    }
    cout << "1 = " << x;
}