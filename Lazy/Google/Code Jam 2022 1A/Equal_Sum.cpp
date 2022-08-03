#include <bits/stdc++.h>
using namespace std;
#define int long long

vector <int> A, B(100); // initial arrays

vector <int> ans;

int sum = 0;

const int MX = 1000000000;

void pre() {
    for(int i = 1; i < MX; i *= 10) {
        for(int j = 1; j <= 9; j++) {
            A.push_back(i * j);
        }
    }
    A.push_back(MX);
    for(int i = 11; i <= 18; i++) {
        A.push_back(i);
        A.push_back(i + 10);
    }
    A.push_back(19);
    A.push_back(32);
    sum = accumulate(A.begin(), A.end(), 0ll);
    for(int i = 0; i < 100; i++) {
        assert(A[i] >= 1 && A[i] <= MX);
    }
    sort(A.begin(), A.end(), greater<int>());
    // cout << (int)A.size() << endl;
    // cout << sum << endl;
}

void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++) {
        cin >> B[i];
    }
    sort(B.begin(), B.end(), greater<int>());
    ans.clear();
    int diff = 0;
    for(int i = 0; i < n; i++) {
        if(diff + B[i] <= MX) {
            ans.push_back(B[i]);
            diff += B[i];
        } else {
            diff -= B[i];
        }
    }
    // cout << diff << endl;
    int push = (sum - diff)/2;
    // cout << sum << " " << diff << " " << push << endl;
    int curr = 0;
    while(push) {
        if(push - A[curr] >= 0) {
            ans.push_back(A[curr]);
            push -= A[curr];
            // cout << A[curr] << " " << push << endl;
        }
        curr++;
    }
    for(auto i : ans) {
        assert(i >= 1 && i <= MX);
        cout << i << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    pre();

    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
    
    return 0;
}