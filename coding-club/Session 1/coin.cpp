// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=657&page=show_problem&problem=2231

#include <bits/stdc++.h>

using namespace std;

int func() {
    int n;
    cin >> n;
    vector <int> v;
    for (int i=0; i<n;i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    if(v.size()==1) {
        cout << 1 << endl;
        return 0;
    }
    long sum = v[0];
    int count = 2;
    for (int i=1; i<v.size()-1;i++) {
        long temp = sum + v[i];
        if(temp < v[i+1]) {
            sum = temp;
            count++;
        }
    }
    cout << count << endl;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    cin >> t;
    for (int i=1;i<=t;i++) {
        func();
    }
    return 0;
}

