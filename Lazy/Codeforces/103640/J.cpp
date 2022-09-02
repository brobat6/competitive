// g++ A.cpp
// ./a < input.txt > output.txt

#include<bits/stdc++.h>
using namespace std;

int w, h;

struct P {
    int x, y, c;

    bool operator <(const P& other) const {
        if(x == 0 && other.x == 0) return y < other.y;
        if(x == 0 && other.x != 0) return true;
        if(x != 0 && other.x == 0) return false;
        if(y == h && other.y == h) return x < other.x;
        if(y == h && other.y != h) return true;
        if(y != h && other.y == h) return false;
        if(x == w && other.x == w) return y > other.y;
        if(x == w && other.x != w) return true;
        if(x != w && other.x == w) return false;
        return x > other.x;
    }
};

bool check(const P& p) {
    if(p.x == 0 || p.x == w) return true;
    if(p.y == 0 || p.y == h) return true;
    return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	map<pair<int, int>, int> c;
    cin >> w >> h;
    int n;
    cin >> n;
    set<P> s;
    for(int i = 0; i < n; i++) {
        P a, b;
        cin >> a.x >> a.y >> b.x >> b.y;
        a.c = i;
        b.c = i;
        if(check(a) && check(b)) {
            s.insert(a);
            s.insert(b);
        }
    }
    stack <int> ss;
    for(auto p : s) {
        if(ss.empty()) ss.push(p.c);
        else if(ss.top() == p.c) ss.pop();
        else ss.push(p.c);
    }
    cout << (ss.empty() ? 'Y' : 'N');
	
	return 0;
}