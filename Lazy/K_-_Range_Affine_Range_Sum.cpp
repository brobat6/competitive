#include <bits/extc++.h>
#include <bits/stdc++.h>
/*
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
*/
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
#define double long double
#define pb push_back
#define sz(x) (int)(x).size()
#define all(v) begin(v),end(v)
#define debug(x) cerr<<#x<<" = "<<x<<'\n'
#define LINE cout<<"\n-----------------\n"
#define endl '\n'
#define VI vector<int>
#define F first
#define S second
#define MP(a,b) make_pair(a,b)
#define rep(i,m,n) for(int i = m;i<=n;++i)
#define res(i,m,n) for(int i = m;i>=n;--i)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/gcd(a,b)
#define Case() int _;cin>>_;for(int Case = 1;Case<=_;++Case)
#define pii pair<int,int>
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
template <typename K, typename cmp = less<K>, typename T = thin_heap_tag> using _heap = __gnu_pbds::priority_queue<K, cmp, T>;
template <typename K, typename M = null_type> using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename cmp = less<K>, typename T = rb_tree_tag> using _tree = tree<K, M, cmp, T, tree_order_statistics_node_update>;
template <typename K, typename M = null_type, typename cmp = less_equal<K>, typename T = rb_tree_tag> using _multitree = tree<K, M, cmp, T, tree_order_statistics_node_update>;
const int N = 1e6+5,L = 20,mod = 998244353,inf = 5e18+5;
VI v;
template<class T>struct SEG{
	int n;
	struct node{
		int l,r;
		T sum;
		pii lz;
		node(){
			l = r = sum = 0;
			lz = {1,0};
		}
	};
	vector<node>arr;
	void init(int _n){
		n = _n;
		arr.clear();
		arr.resize(n<<2);
	}
	void pull(node &ans,node left,node right){
		ans.sum = left.sum+right.sum;
		ans.sum%=mod;
		ans.l = left.l,ans.r = right.r;
	}void pull(int idx){
		pull(arr[idx],arr[idx<<1],arr[idx<<1|1]);
	}
	void push(int idx){
		if(arr[idx].lz.S==0)return;
		arr[idx<<1].sum*=arr[idx].lz.F;
		arr[idx<<1].sum%=mod;
		arr[idx<<1].sum+=(arr[idx<<1].r-arr[idx<<1].l+1)*arr[idx].lz.S;
		arr[idx<<1].sum%=mod;
		arr[idx<<1].lz = {(arr[idx<<1].lz.F*arr[idx].lz.F)%mod,((arr[idx<<1].lz.S*arr[idx].lz.F)%mod+arr[idx].lz.S)%mod};
		arr[idx<<1|1].sum*=arr[idx].lz.F;
		arr[idx<<1|1].sum%=mod;
		arr[idx<<1|1].sum+=(arr[idx<<1|1].r-arr[idx<<1|1].l+1)*arr[idx].lz.S;
		arr[idx<<1|1].sum%=mod;
		arr[idx<<1|1].lz = {(arr[idx<<1|1].lz.F*arr[idx].lz.F)%mod,((arr[idx<<1|1].lz.S*arr[idx].lz.F)%mod+arr[idx].lz.S)%mod};
		arr[idx].lz = {1,0};
	}
	void build(const vector<T>&v,int l,int r,int idx){
		if(l==r){
			arr[idx].sum = v[l];
			arr[idx].l = arr[idx].r = l;
			arr[idx].lz = {1,0};
			return;
		}
		int m = (l+r)>>1;
		build(v,l,m,idx<<1);
		build(v,m+1,r,idx<<1|1);
		pull(idx);
	}void build(const vector<T>&v,int r){
		build(v,1,r,1);
	}
	void update(int l,int r,pii y,int idx = 1){
		if(l<=arr[idx].l and arr[idx].r<=r){
			arr[idx].sum*=y.F;
			arr[idx].sum%=mod;
			arr[idx].sum+=(arr[idx].r-arr[idx].l+1)*y.S;
			arr[idx].sum%=mod;
			arr[idx].lz = {(arr[idx].lz.F*y.F)%mod,((arr[idx].lz.S*y.F)%mod+y.S)%mod};
			return;
		}
		push(idx);
		int m = (arr[idx].l+arr[idx].r)>>1;
		if(l<=m)update(l,r,y,idx<<1);
		if(r>m)update(l,r,y,idx<<1|1);
		pull(idx);
	}
	node query(int l,int r,int idx = 1){
		if(l<=arr[idx].l and arr[idx].r<=r){
			return arr[idx];
		}
		push(idx);
		int m = (arr[idx].l+arr[idx].r)>>1;
		node ans,left,right;
		if(l<=m)left = query(l,r,idx<<1);
		if(r>m)right = query(l,r,idx<<1|1);
		pull(ans,left,right);
		return ans;
	}
};
template<class T>struct BIT{
	int n;
	vector<T>arr;
	void init(int _n){
		n = _n;
		arr.assign(n,0);
	}
	int lowbit(int x){
		return x&(-x);
	}
	int query(int x){
		int ans = 0;
		for(int i = x;i>0;i-=lowbit(i)){
			ans+=arr[i];
		}
		return ans;
	}
	void update(int x,int y){
		for(int i = x;i<=n;i+=lowbit(i)){
			arr[i]+=y;
		}
	}
};
void readfile(){
	freopen("peacefulsets.in","r",stdin);
	freopen("peacefulsets.out","w",stdout);
}
void solve(){
	int n,q;
	cin>>n>>q;
	SEG<int>seg;
	seg.init(n+5);
	VI v(n+5);
	rep(i,1,n){
		cin>>v[i];
	}
	seg.build(v,n);
	while(q--){
		int opt;cin>>opt;
		if(opt==1){
			int l,r;
			cin>>l>>r;
			l++;
			cout<<seg.query(l,r).sum<<endl;
		}
		else{
			int l,r,a,b;
			cin>>l>>r>>a>>b;
			l++;
			seg.update(l,r,{a,b});
		}
	}
}
signed main(){
	IOS;
	//readfile();
	solve();
	return 0;
}