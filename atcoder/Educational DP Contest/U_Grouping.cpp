#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)

/*
Initially build an array ans[2^16] ---> ans[j] is the score assuming the 1 bits of j are in the same set. O(n^2 * 2^n)
Next, build dp[2^15] ---> Here 1-bit represents the given rabbit has been allocated. 
Answer for dp[given k bits set] = Optimum answer by adding any two sub-groupings of these k bits.
k bits ---> 2^k subgroupings.
There will be nCr(16, k) such bits.
Time complexity = sum of nCr(16, k)*(2^k) from 1 to n. ---> 3^n
Might JUST be doable.
Will also have to sort values by number of bits.
*/

const int N = 16;
const int M = 65536; //2^16
int n, m;
int arr[N][N], ans[M], dp[M]; 
// arr->input ; ans->described above ; dp-> The optimum answer assuming these rabbits have been allocated.
vector<int> v; // sort values by builtinpopcount
vector<vector<int>> bits(M); // which bits are set in M. 

void findBits(int x) {
    int i = x;
    int ind = 0;
    while(i) {
        if(i & 1) bits[x].push_back(ind);
        ind++;
        i >>= 1; 
    }
}

void setAns(int x) {
    int c = bits[x].size();
    forn(i, 0, c) forn(j, i+1, c) ans[x] += arr[bits[x][i]][bits[x][j]];
}

bool comp(int a, int b) {
    return __builtin_popcount(a) < __builtin_popcount(b);
}

void pre() {
    cin >> n;
    m = 1<<n;
    forn(i, 0, n) forn(j, 0, n) cin >> arr[i][j];
    forn(i, 0, m) {ans[i] = 0; dp[i] = 0; findBits(i); v.push_back(i);}
    forn(i, 0, m) setAns(i);
    sort(v.begin(), v.end(), comp);
}

void build(int x) {
    // build dp[x] based on previous dp's already built.
    // We need to generate all subsets of bits[x]. 
    // For each pair of subsets generated, generate the corresponding values to be taken from dp.
    // Then take their sums and maximise it.
    // DONT FORGET THE EXTRA CASE OF dp[x] = max(dp[x], ans[x]).
    // cout << x << endl;
    int length = bits[x].size();
    int snum = 0;
    int e = 1<<length;
    while(snum<e) {
        int f = 0, s = 0;
        for(int i = 0; i < length; i++) {
            int t = snum&(1<<i);
            if(t==0) f += (1<<bits[x][i]);
            else s += (1<<bits[x][i]);    
        }
        snum++;
        if(f==0 || s==0) continue;
        dp[x] = max(dp[x], dp[f] + dp[s]);
    }
    // cout << dp[x] << " ";
    dp[x] = max(dp[x], ans[x]);
    // cout << dp[x] << endl;
}

void solve() {
    pre();
    int start_index = 0;
    forn(i, 0, m) {
        if(__builtin_popcount(v[i]) > 1) {
            start_index = i;
            break;
        }
    }
    // cout << dp[7];
    // for(auto i : bits[6]) cout << i << " ";
    // cout << ans[6];
    forn(i, start_index, m) {
        build(v[i]);
    }
    cout << dp[m-1];
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}