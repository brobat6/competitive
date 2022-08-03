#include <bits/stdc++.h>
using namespace std;

#define int long long
// #define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> child(n);
    for(int i = 0; i < n; i++) {
        child[i].push_back(i);
    }
    for(int i = 1; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            cout << "? 3 " << 1 << " " << i + 1 << " " << j + 1 << endl;
            int x;
            cin >> x;
            if(x == 1) {
                child[i].push_back(j);
            } else {
                cout << "? 3 " << 1 << " " << j + 1 << " " << i + 1 << endl;
                cin >> x;
                if(x == 1) {
                    child[j].push_back(i);
                }
            }
        }
    }
    sort(child.begin(), child.end(), [&](vector<int> a, vector<int> b) {
        return (int)a.size() < (int)b.size();
    });
    vector <int> parent(n, -1);
    for(int i = 0; i < n; i++) {
        if(child[i][0] == 0) continue;
        for(int j = 1; j < (int)child[i].size(); j++) {
            if(parent[child[i][j]] == -1) {
                parent[child[i][j]] = child[i][0];
            }
        }
    }
    for(int i = 1; i < n; i++) {
        if(parent[i] == -1) {
            parent[i] = 0;
        }
    }
    cout << "! " << endl;
    for(int i = 1; i < n; i++) {
        cout << i + 1 << " " << parent[i] + 1 << endl;
    }
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}