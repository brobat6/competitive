// g++ A.cpp
// ./a < input.txt > output.txt

#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
    cin >> s;
    int curr = -1;
    vector<string> temp =  {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    for(int i = 0; i < 7; i++) {
        if(s == temp[i]) {
            curr = i; 
        }
    }
    assert(curr != -1);
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector <int> w(n);
    for(int i = 0; i < n; i++) {
        int date = (((curr - v[i]) % 7) + 7) % 7;
        if(date == 0) {

        } else if(date == 1) {
            if(w[i] < v[i]) w[i] += 30;
            if(w[i] < v[i]) w[i] += 32;
        } else if(date == 2) {
            if(w[i] < v[i]) w[i] += 30;
            if(w[i] < v[i]) w[i] += 31;
        } else if(date == 3) {
            if(w[i] < v[i]) w[i] += 32;
        } else if(date == 4) {
            if(w[i] < v[i]) w[i] += 31;
        } else {
            assert(false);
        }
        // Now it's a Monday.
        int diff = (v[i] - w[i]) / 91;
        w[i] += diff * 91;
        if(w[i] < v[i]) w[i] += 30;
        if(w[i] < v[i]) w[i] += 30;
        if(w[i] < v[i]) w[i] += 31;
        if(v[i] == 0 && w[i] == 0) {
            // Corner case.
            if(curr == 0) w[i] = 30;
            if(curr == 1) w[i] = 30;
            if(curr == 2) w[i] = 30;
            if(curr == 3) w[i] = 32;
            if(curr == 4) w[i] = 31;
        }
    }
    vector <int> x(n);
    for(int i = 0; i < n; i++) {
        x[i] = w[i] - v[i];
    }
    cout << *min_element(x.begin(), x.end());
	
	return 0;
}