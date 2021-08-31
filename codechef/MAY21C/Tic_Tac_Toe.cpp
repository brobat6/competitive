//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 200100
#define MOD 1000000007

int n, num_vic;
int arr[3][3];
int vic;
int num_vic_x;

int check() {
    int temp = 0;
    num_vic_x = 0;
    forn(i, 3) {
        if(arr[i][0]==0) {
            if(arr[i][1]==0) {
                if(arr[i][2]==0) {
                    temp += 1;
                    vic = 0;
                    num_vic_x += 1;
                }
            }
        }
        if(arr[i][0]+arr[i][1]+arr[i][2]==3) {
            temp += 1;
            vic = 1;
        }
    }
    forn(i, 3) {
        if(arr[0][i]==0) {
            if(arr[1][i]==0) {
                if(arr[2][i]==0) {
                    temp += 1;
                    vic = 0;
                    num_vic_x += 1;
                }
            }
        }
        if(arr[0][i]+arr[1][i]+arr[2][i]==3) {
            temp += 1;
            vic = 1;
        }
    }
    forn(i, 2) {
        if(arr[0][0]==i) {
            if(arr[1][1]==i) {
                if(arr[2][2]==i) {
                    temp += 1;
                    vic = i;
                    if(i==0) num_vic_x += 1;
                }
            }
        }
        if(arr[2][0]==i) {
            if(arr[1][1]==i) {
                if(arr[0][2]==i) {
                    temp += 1;
                    vic = i;
                    if(i==0) num_vic_x += 1;
                }
            }
        }
    }
    return temp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    cin >> t;
while(t--) {
    char c;
    int num_o = 0;
    int num_x = 0;
    forn(i, 3) {
        forn(j, 3) {
            cin >> c;
            if(c=='O') {
                arr[i][j] = 1;
                num_o += 1;
            }
            if(c=='X') {
                arr[i][j] = 0;
                num_x += 1;
            }
            if(c=='_') arr[i][j] = -1;
        }
    }
    // cout << num_o << " " << num_x << endl;
    // forn(i, 3) forn(j, 3) cout << arr[i][j] << " ";
    if(!((num_x==num_o)||(num_x-num_o==1))) {
        cout << 3 << endl;
        continue;
    }
    num_vic = 0;
    vic = -1;
    num_vic = check();
    // cout << num_vic << "z" << endl;
    if(num_vic_x==2) {
        if(num_x==5&&num_o==4) {
            cout << 1 << endl;
            continue;
        }
    } 
    if(num_vic>1) {
        cout << 3 << endl;
        continue;
    }
    if(num_vic==1) {
        if(vic==0) {
            if(num_x!=(num_o+1)) {
                cout << 3 << endl;
                continue;
            }
        }
        if(vic==1) {
            if(num_x!=num_o) {
                cout << 3 << endl;
                continue;
            }
        }
    }
    if((num_x+num_o==9)||(num_vic==1)) {
        cout << 1 << endl;
    }
    else {
        cout << 2 << endl;
    }
    // cout << -1 << endl;
}
    return 0;
}



