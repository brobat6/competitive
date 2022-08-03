#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 200100;
const int MOD = (int)1E9 + 7;
const int INF = (int)9E18;
const char nl = '\n';

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int> vks(n);
        bool fl = 0;
        for(int i = 0; i < n; i++) cin>>vks[i];
        map<vector<int>, int> M;
        for(int i = 0; i < n; i++) {
            vector<int> temp;
            for(int j = 0; j < vks[i]; j++) {
                int t; cin>>t;
                temp.push_back(t);
            }
            sort(temp.begin(), temp.end());
            M[temp]++;
        }
        int m; cin>>m;
        vector<int> mps(m);
        for(int i = 0; i < m; i++) cin>>mps[i];
        for(int i = 0; i < m; i++) {
            vector<int> temp;
            for(int j = 0; j < mps[i]; j++) {
                int t; cin>>t;
                temp.push_back(t);
            }
            sort(temp.begin(), temp.end());
            if(M.find(temp) == M.end()) {
                fl = 1;
            }
            M[temp] --;
            if(M[temp] < 0) {
                fl = 1;
            }
        }
        if(fl) {
            cout << "No\n";
            continue;
        }
        if(m!=n) {
            cout<<"No\n";
        }
        else {
            cout<<"Yes\n";
        }
    }
    
    return 0;
}