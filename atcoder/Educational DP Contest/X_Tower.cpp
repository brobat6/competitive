#include <bits/stdc++.h>
using namespace std;

const int MAXW = 20100;

// See Errichto's tutorial (Topic : Exchange Arguments).

struct Block {
  	int w, s;
  	long long v;
};

bool comp(Block a, Block b) {
  	return a.w + a.s < b.w + b.s;
}

int main() {
  	int n; 
  	cin >> n;
  	vector <Block> v(n);
  	for(int i = 0; i < n; i++) {
    	cin >> v[i].w >> v[i].s >> v[i].v;
  	}
  	sort(v.begin(), v.end(), comp);
  	vector <long long> dp(MAXW, 0);
  	for(int i = 0; i < n; i++) {
    	for(int j = v[i].s; j >= 0; j--) {
      	dp[j + v[i].w] = max(dp[j + v[i].w], dp[j] + v[i].v);
    	}
  	}
  	cout << *max_element(dp.begin(), dp.end());
	return 0;
}