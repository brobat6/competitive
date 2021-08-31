// https://codeforces.com/contest/1494/problem/D

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 501

int n, num_emp;
int salary[MAXN];
int parent[MAXN];

struct Store {
    int x;
    int y;
    int z;
};
Store s[MAXN*MAXN];

bool comp(Store a, Store b) {
    if(a.z==b.z) {
        if(a.x==b.x) {
            return a.y < b.y;
        }
        else {
            return a.x < b.x;
        }
    }
    else {
        return a.z < b.z;
    }
}

int find(int x) {
    if(x==parent[x]) return x;
    else return(find(parent[x]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    cin >> n;
    forn(i, MAXN) parent[i] = i;
    int temp = 0, dummy;
    forn(i, n) {
        forn(j, n) {
            if(i>j) {
                cin >> dummy;
            }
            else if(i==j) {
                cin >> salary[i];
            }
            else {
                s[temp].x = i;
                s[temp].y = j;
                cin >> s[temp].z;
                temp++;
            }
        }
    }
    // Now we have inputs of the form s{i,j,k} where k is salary of supervisor of i and j.
    sort(s, s+temp, comp);
    // Size of s = temp = n(n-1)/2
    // forn(i, temp) {
    //     cout << s[i].x << " " << s[i].y << " " << s[i].z << endl;
    // }
    num_emp = n-1;
    forn(i, temp) {
        // cout << s[i].x << " " << s[i].y << endl;
        if(parent[find(s[i].x)]!=parent[find(s[i].y)]) {
            
            if(salary[find(s[i].x)]==s[i].z) {
                parent[s[i].y] = parent[s[i].x];
                continue;
            }
            if(salary[find(s[i].y)]==s[i].z) {
                parent[s[i].x] = parent[s[i].y];
                continue;
            }
            num_emp++;
            // cout << s[i].x << " " << s[i].y << endl;
            salary[num_emp] = s[i].z;
            parent[find(s[i].x)] = num_emp;
            parent[find(s[i].y)] = num_emp;
        }
    }
    cout << ++num_emp << endl;
    forn(i, num_emp) {
        cout << salary[i] << " ";
    }
    cout << endl;
    forn(i, MAXN) {
        if(i==parent[i]) {
            cout << (i+1) << endl;
            break;
        }
    }
    forn(i, num_emp) {
        if(i==parent[i]) continue;
        cout << (i+1) << " " << (parent[i]+1) << endl;
    }
    return 0;
}
