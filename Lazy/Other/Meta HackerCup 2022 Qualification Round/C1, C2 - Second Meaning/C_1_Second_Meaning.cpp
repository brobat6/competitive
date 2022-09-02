#include <bits/stdc++.h>
using namespace std;
// #define int long long

vector<vector<char>> code;
map<string, pair<string, string>> mp;

void pre() {
    for(int y = 1; y <= 10; y++) {
        for(int i = 0; i < (1<<y); i++) {
            int x = i;
            vector<char> t;
            for(int j = 0; j < y; j++) {
                if(x % 2) t.push_back('-');
                else t.push_back('.');
                x >>= 1;
            }
            code.push_back(t);
        }
    }
    reverse(code.begin(), code.end());
    // for(auto i : code) {
    //     for(auto j : i) cout << j;
    //     cout << '\n';
    // }
    mp[".."] = {".-", "--"};
    mp["--"] = {"-.", ".."};
    mp[".-"] = {"..", "--"};
    mp["-."] = {"..", "--"};
}

bool check(vector<char> &a, vector<char> &b) {
    // check if a is a substring of b or not.
    if((int)a.size() > (int)b.size()) return check(b, a);
    int n = b.size();
    int m = a.size();
    for(int i = 0; i <= n - m; i++) {
        bool equal = true;
        for(int j = 0; j < m; j++) {
            if(a[j] != b[i + j]) {
                equal = false;
                break;
            }
        }
        if(equal) return true;
    }
    return false;
}

void solve_corner(vector <char> &v, int needed) {
    int n = v.size();
    if(n == 1) {
        cout << '\n';
        int done = 0;
        for(int i = 0; i < (int)code.size(); i++) {
            if((int)code[i].size() == 8) {
                cout << (v.front() == '.' ? '-' : '.');
                for(auto j : code[i]) cout << j;
                cout << (v.front() == '.' ? '-' : '.');
                cout << '\n';
                done++;
                if(done == needed - 1) return;
            }
        }
        assert(false);
    } else {
        cout << '\n';
        int done = 0;
        string temp;
        temp += v[0];
        temp += v[1];
        for(int i = 0; i < (int)code.size(); i++) {
            if((int)code[i].size() == 6) {
                // first output.
                cout << mp[temp].first;
                for(auto j : code[i]) cout << j;
                cout << mp[temp].first;
                cout << '\n';
                done++;
                if(done == needed - 1) return;
                // second output.
                cout << mp[temp].second;
                for(auto j : code[i]) cout << j;
                cout << mp[temp].second;
                cout << '\n';
                done++;
                if(done == needed - 1) return;
            }
        }
        assert(false);
    } 
}

void solve() {
    int n;
    cin >> n;
    vector <char> v;
    {
        string s;
        cin >> s;
        for(auto i : s) v.push_back(i);
    }
    if((int)v.size() <= 2) {
        solve_corner(v, n);
        return;
    }
    vector <vector<char>> ans;
    ans.push_back(v);
    for(int i = 0; i < (int)code.size(); i++) {
        bool pos = true;
        for(int j = 0; j < (int)ans.size(); j++) {
            if(check(ans[j], code[i])) {
                pos = false;
                break;
            }
        }
        if(pos) {
            ans.push_back(code[i]);
            if((int)ans.size() == n) {
                break;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    ans.pop_back();
    assert((int)ans.size() == n - 1);
    cout << '\n';
    for(auto i : ans) {
        for(auto j : i) cout << j;
        cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    freopen("second_meaning_input.txt", "r", stdin);
    freopen("second_meaning_output.txt", "w", stdout);
    
    pre();

    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        cout << "Case #" << I << ": ";
        solve();
    }
    
    return 0;
}