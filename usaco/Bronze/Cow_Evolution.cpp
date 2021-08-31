// http://usaco.org/index.php?page=viewproblem2&cpid=941

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    freopen("evolution.in","r",stdin);
    freopen("evolution.out","w",stdout);
    int n,temp;
    string s;
    cin >> n;
    map <string, vector<int>> m;
    for(int i=0; i<n; i++) {
        cin >> temp;
        if(temp==0) continue;
        for(int j=0; j<temp; j++) {
            cin >> s;
            m[s].push_back(temp);
        }
    }
    s = "yes";
    int diff;
    for(auto i : m) {
        diff = 1;
        sort(i.second.begin(),i.second.end());
        int size = i.second.size();
        int arr[size];
        for(int j=0; j<size; j++) {
            arr[j] = i.second[j];
        }
        for(int j=1; j<size; j++) {
            temp = arr[j]-arr[j-1];
            if(temp==0) {
                diff = 0;
                break;
            }
        }
        if(diff==0) {
            s = "no";
            break;
        }
    }
    cout << s;
    return 0;
}
