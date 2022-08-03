#include <bits/stdc++.h>
using namespace std;
#define int long long

pair<int, int> find(int x, int n) {
    // find the x^th pair in O(n)
    int f = 1;
    int s = 0;
    int d = 0;
    while(d + (n - f) < x) {
        d += n - f;
        f++;
    }
    s = f;
    while(d < x) {
        d++;
        s++;
    }
    return {f - 1, s - 1};
}

void print(pair<int, int> x) {
    cout << x.first << " " << x.second << '\n';
}

void print(vector <int> &v) {
    int n = (int)v.size();
    for(int i = 0; i < n; i++) cout << v[i] + 1 << " ";
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, l, r;
    cin >> n >> l >> r;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        v[i] = i;
    }
    auto f = find(l, n);
    auto s = find(r, n);
    // print(f);
    // print(s);
    if(f.first == s.first) {
        while(f.second <= s.second) {
            swap(v[f.first], v[f.second]);
            f.second++;
        }
    }
    else {
        while(f.second < n) {
            swap(v[f.first], v[f.second]);
            f.second++;
        }
        // print(v);
        f.first++; 
        f.second = f.first + 1;
        vector <int> w;
        for(int i = 0; i < f.first; i++) {
            w.push_back(v[i]);
        }
        for(int i = f.first; i < s.first; i++) {
            w.push_back(v[n - (i - f.first) - 1]);
        }
        for(int i = s.first; i < n; i++) {
            w.push_back(v[f.first + i - s.first]);
        }
        v = w;
        auto t = s;
        t.second = t.first + 1;
        while(t.second <= s.second) {
            swap(v[t.first], v[t.second]);
            t.second++;
        }
    }
    for(int i = 0; i < n; i++) cout << v[i] + 1 << " ";
    

    
    return 0;
}