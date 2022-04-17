#include <bits/stdc++.h>
using namespace std;

int solve(string input_file, string output_file) {
    const char *in_conv = input_file.c_str();
    const char *out_conv = output_file.c_str();
    freopen(in_conv, "r", stdin);
    freopen(out_conv, "w", stdout);

    int nmax=100,mmax=100,valmax=100,valmin=0;
    int n,m;
    cin >> n >> m;
    if (n>nmax || n<0 || m>mmax || m<0) {
        cout << n << " " << m << endl;
        cout << "Invalid Input!" << '\n';
        return 0;
    }
    int arr[n][m];
    bool ck=false;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> arr[i][j];
            if (arr[i][j]<valmin || arr[i][j]>valmax) {
                ck=true;
            }
        }
    }
    if (ck) {
        cout << "Values not in given range!" << '\n';
        return 0;
    }
    int posi=0,posj=0;
    int di=0,dj=1;
    int vis[n+2][m+2];
    memset(vis,0,sizeof(vis));
    for (int i=0;i<(n+2);i++) {
        vis[i][0]=1;
        vis[i][m+1]=1;
    }
    for (int i=0;i<(m+2);i++) {
        vis[0][i]=1;
        vis[n+1][i]=1;
    }
    while (!vis[posi+1][posj+1]) {
        vis[posi+1][posj+1]=1;
        cout << arr[posi][posj] << " ";
        posi+=di;
        posj+=dj;
        if (vis[posi+1][posj+1]) {
            posi-=di;
            posj-=dj;
            if (!dj) {
                dj=-di;
                di=0;
            }
            else if (!di) {
                di=dj;
                dj=0;
            }
            posi+=di;
            posj+=dj;
        }
    }
    cout << '\n';
    return 0;
}

int main() {

    string inp, out;
    
    inp = "input/input09.txt";
    out = "output/output09.txt";
    solve(inp, out);

    return 0;
}