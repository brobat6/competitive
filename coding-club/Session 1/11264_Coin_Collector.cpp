// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2231

#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a;
		for(int i=0;i<n;i++) {
			int k;
			cin>>k;
			a.push_back(k);
		}
		
		if(a.size() == 1) {
			cout<<1<<endl;
			continue;
		}
		
		long sum = a[0];
		int count = 2;
		
		for(int i=1;i<a.size()-1;i++){
			long temp = sum+a[i];
			if(temp < a[i+1]) {
				sum = temp;
				count++;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}