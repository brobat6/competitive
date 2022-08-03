#include <bits/stdc++.h>
using namespace std;
#define int long long

struct S {
    int a, b, c;

    bool operator <(const S & other) const {
        if(c == other.c) {
            return (a + b) > (other.a + other.b);
        }
        return c < other.c;
    }
};

// Is a less than b? If TRUE then yes, if FALSE then no. 
bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

bool cmp(int a, int b) {
    return a > b;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // set <S> z;

    // priority_queue<S> z;

    vector <S> z;

    sort(z.begin(), z.end(), [&](S x, S y) {
        if(x.c == y.c) {
            return (x.a + x.b) > (y.a + y.b);
        }
        return x.c < y.c;
    });

    priority_queue<int, vector<int>, greater<int>> p; // min-heap

    priority_queue<pair<int, int>, vector<pair<int, int>>, function<bool(pair<int, int>, pair<int, int>)>> pq(compare);
    
    set<int, decltype(cmp)> s(cmp);

    return 0;
}