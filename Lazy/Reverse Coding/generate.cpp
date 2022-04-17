#include <bits/stdc++.h>
using namespace std;

int solve(string input_file, string output_file) {
    const char *in_conv = input_file.c_str();
    const char *out_conv = output_file.c_str();
    // freopen(in_conv, "r", stdin);
    freopen(out_conv, "w", stdout);

    // Code goes here.
    int t;
    cin >> t;
    int tmax=100;
    if (t>tmax || t<0) {
        cout << "Invalid Input!" << '\n';
        // getchar(); getchar();
        return 0;
    }

    int val1max=100,val1min=1,val2max=50,val2min=1;
    while(t--) {
        int val1,val2;
        cin >> val1 >> val2;
        if (val1>val1max || val1<val1min || val2>val2max || val2<val2min) {
            cout << "Invalid Input!" << '\n';
            continue;
        }
        int dx=1;
        int pos=1;
        for (int i=1;i<=val1;i++) {
            cout << pos << " ";
            if (val2==1) {
                continue;
            }
            pos+=dx;
            if (pos>val2) {
                pos=val2-1;
                dx*=-1;
            }
            else if (pos<=0) {
                pos=2;
                dx*=-1;
            }
        }
        cout << '\n';
    }
    // getchar(); getchar();
    return 0;
}

int main() {

    string inp, out;
    
    inp = "UniqueChars/input/input04.txt";
    // out = "UniqueChars/output/output04.txt";
    out = "special.txt";
    solve(inp, out);

    return 0;
}