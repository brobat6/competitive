#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pi pair<int,int>
 
 
void f() {
    int n;
    cin>>n;
    vector<int> v;
    unordered_map<ll, int> mp;
 
    for(int i=0;i<n;i++) {
        int k = 0;
        cin>>k;
        mp[k]++;
    }
    
    for(auto x:mp) {
        v.push_back(x.second);
    }
    
    sort(v.begin(), v.end());
    int kk = v.size();
    vector<int> pre(kk);
    pre[0] = v[0];
    for(int i=1;i<kk; i++) pre[i] = pre[i-1]+v[i];
    ll mini = LONG_MAX;
    
    //for(int i=0;i<v.size();i++) cout<<"a"<<v[i]<<"a";
    
    for(int i=0;i<kk;i++) {
        
        ll ans = 0;
        
        ans += pre[v.size()-1] - pre[i];
        ans -= v[i]*(v.size()-1-i);
        
        if(i > 0) ans += pre[i-1];
        
        //cout<<v[i]<<" "<<ans<<"\n";
        mini = min(mini, ans);
    }
    cout<<mini<<"\n";
}
 
 
 
int main() {
	// your code goes here
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int t;
	cin>>t;
	while(t--) {
	    f();
	}
	
	return 0;
}