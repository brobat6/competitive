// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=658&page=show_problem&problem=3051

#include <bits/stdc++.h>

using namespace std;

int func() {
    int n,p,q,num=0,wt=0,temp;
    cin >> n >> p >> q;
    for(int i=1;i<=n;i++) {
        cin >> temp;
        if(((temp+wt)<=q)&&(num<p)) {
            num += 1;
            wt += temp;
        }
        else {
            break;
        }
    }
    return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    cin >> t;
    for(int j=1;j<=t;j++) {
        cout << "Case " << j << ": " << func() << endl;
    }
    return 0;
}