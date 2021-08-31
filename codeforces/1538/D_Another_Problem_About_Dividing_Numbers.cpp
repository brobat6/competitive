// //

// #include <bits/stdc++.h>
// #define forn(i, n) for (int i = 0; i < int(n); i++)
// using namespace std;
// #define N 200100
// #define MOD 1000000007

// int a, b, k;

// int func(int n) {
//     int ans = 0;
//     while(n%2==0) {
//         ans++;
//         n = n/2;
//     }
//     for(int i=3; (i*i)<=n; i = i+2) {
//         while(n%i==0) {
//             ans++;
//             n = n/i;
//         }
//     }
//     if(n>2) ans++;
//     return ans;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     cout.precision(numeric_limits<double>::max_digits10);
//     freopen("x.txt", "r", stdin);
//     freopen("y.txt", "w", stdout);
//     // cout << func(900800009);
//     int t;
//     cin >> t;
// while(t--) {
//     cin >> a >> b >> k;
//     if(a>b) swap(a, b);
//     cout << "\n";
//     if((a==b)&&(k==1)) {
//         cout << "NO";
//         continue;
//     }
//     if(k==1) {
//         if(b%a==0) cout << "YES";
//         else cout << "NO";
//         continue;
//     }
//     int x, y;
//     x = func(a);
//     y = func(b);
//     if((x+y)>=k) cout << "YES";
//     else cout << "NO";
// }
//     return 0;
// }

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;

#define ll          long long
#define vi          vector<int>
#define vll         vector<ll>
#define pll         pair<ll, ll>
#define pii         pair<int, int>
#define ld          long double
#define ff          first
#define ss          second
#define vs          vector<string>
#define vc          vector<char>
#define vpii        vector<pii>
#define vpll        vector<pll>
#define vb          vector<bool>
#define mp          make_pair
#define pb          push_back
#define ppb         pop_back
#define all(x)      x.begin(), x.end()
#define pqb         priority_queue <int>
#define pqs         priority_queue <int, vi, greater <int>>
#define ps(x, y)    fixed << setprecision(y) << x
#define mem0(arr)   memset(arr, 0, sizeof(arr))
#define mem1(arr)   memset(arr, -1, sizeof(arr))
#define endl        '\n'

const ll INF       = 2e18;
const ll mod       = 1000000007;
const ll mod2      = 998244353;
const ld  PI        = 3.141592653589793238462;

template <typename T> void sort    (vector<T>& v) {std::sort(v.begin(),v.end());}
template <typename T> void sortbig (vector<T>& v) {std::sort(v.begin(),v.end(),greater<T>());}
template <typename T, typename Y> ostream& operator << (ostream& x, const pair<T,Y>& v) {x<<v.ff<<" "<<v.ss; return x;}
template <typename T, typename Y> ostream& operator << (ostream& x, const map<T, Y>& v) {for (auto it : v) x << it.ff << ": " << it.ss << endl; return x;}
template <typename T, typename Y> istream& operator >> (istream& x, pair<T,Y>& v) {x>>v.ff>>v.ss; return x;}
template <typename T> istream& operator >> (istream& x,vector<T>& v) {for(T& it:v) x>>it;return x;}
template <typename T> ostream& operator << (ostream& x,const vector<T>& v) {for(int i=0;i<(int)v.size();i++) x<<v[i]<<" ";return x;}
template <typename T> ostream& operator << (ostream& x,const set<T>& v) {for(auto it:v) x<<it<<" ";return x;}
template <typename T> ostream& operator << (ostream& x,const multiset<T>& v) {for(auto it:v) x<<it<<" ";return x;}
//typedef tree<int, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update> Ordered_set;

#ifdef RAGH_A_VOID
#define debug(x) cerr << #x <<": "; print(x); cerr << endl;
#else
#define debug(x);
#endif

void print (int t)          {cerr << t;}
void print (ll t)           {cerr << t;}
void print (char t)         {cerr << t;}
void print (ld t)           {cerr << t;}
void print (double t)       {cerr << t;}
void print (const string& t){cerr << t;}

template <class T, class V> void print(pair <T, V> p);
template <class T, class V> void print(map <T, V> v);
template <class T, class V> void print(pair <T, V> p) {cerr << "("; print(p.ff); cerr << ","; print(p.ss); cerr << ")";}
template <class T, class V> void print(map <T, V> v) {for (auto i : v) {print(i); cerr << " ";}}
template <class T> void print(vector <T> v);
template <class T> void print(set <T> v);
template <class T> void print(multiset <T> v);
template <class T> void print(vector <T> v)   {for (T i : v) {print(i); cerr << " ";}}
template <class T> void print(set <T> v)      {for (T i : v) {print(i); cerr << " ";}}
template <class T> void print(multiset <T> v) {for (T i : v) {print(i); cerr << " ";}}

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
inline ll expo(ll a, ll b, ll mm) {ll res = 1; while (b > 0) {if (b & 1) res = (res * a) % mm; a = (a * a) % mm; b = b >> 1;} return res;}
inline ll invprime(ll a, ll b) {return expo(a, b - 2, b);} // for prime
inline ll mulmod(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll divmod(ll a, ll b, ll m) {a = a % m; b = b % m; return (mulmod(a, invprime(b, m), m) + m) % m;} // only works with prime
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;}
inline ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll invnonprime(ll a, ll b) {ll arr[3]; if(gcd(a, b) != 1){return -1;} extendgcd(a, b, arr); if(arr[0] < 0){arr[0] += b;} return arr[0];} //for non prime b (-1 is not possible)
inline ll addmod(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
inline ll submod(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
inline ll sumOfDigits(ll n) {ll sum = 0; while(n) {sum += n % 10; n /= 10;} return sum;}
ll nCr(ll n, ll r) {ll p = 1, k =1; if(n-r>r) r = n-r; if(r == 0) return 1; while(r) {p *= n; k *= r; ll m = gcd(p, k); p /= m; k /= m; n--; r--;} return p;}
ll nCrmod(ll n, ll r, vll& fact, ll mm) {return divmod(fact[n], mulmod(fact[r], fact[n-r], mm), mm);}
vector<ll> sieve(ll n) {ll*arr = new ll[n + 1](); vll v; for (ll i = 2; i <= n; i++)if (arr[i] == 0) {v.push_back(i); for (ll j = 2 * i; j <= n; j += i)arr[j] = 1;} delete[] arr; return v;}
vector<ll> makesieve(vll& arr, ll n) {vll v; for (ll i = 2; i <= n; i++)if (arr[i] == 0) {v.push_back(i); for (ll j = 2 * i; j <= n; j += i)arr[j] = 1;} return v;}
void makefact(vll& arr, ll n, ll mm) { arr[0] = arr[1] = 1; for(ll i = 2; i <= n; i++) { arr[i] = arr[i - 1] * i; arr[i] %= mm;}}
inline void google(ll x) {cout << "Case #" << x << ": ";}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*--------------- vi -> vll, vpii -> vpll, int -> ll --------------------------------------*/


map<ll, ll> cache;

ll numDivisors(ll n){
    ll ans = 0;
    if(cache.find(n) != cache.end()){
        return cache[n];
    }
    ll temp = n;
    while((n%2) == 0){
        n /= 2;
        ans++;
    }
    for(ll i = 3; i * i <= n; i+=2){
        if((n%i)==0){
            while((n%i) == 0){
                n/=i;
                ans++;
            }
        }
    }
    if(n > 1){
        ans++;
    }
    return cache[temp] = ans;
}



signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
// #ifdef RAGH_A_VOID
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     freopen("error.txt", "w", stderr);
// #endif
    clock_t t1, t2;
    t1 = clock();



    int tc = 0, tt = 1;
    cin >> tt;
    while (tc++ < tt)
    {

        ll a, b, k;
        cin >> a >> b >> k;


        if(a == b and k == 0){
            cout << "YES" << endl;
            continue;
        }

        ll g = gcd(a, b);
        ll low = 2, high = 1;
        if((g == a or g == b) and (a != b)){
            low = 1;
        }

        ll valA = numDivisors(a);
        ll valB = numDivisors(b);

        high = valA + valB;

        if(k >= low and k <= high){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }








        //  check corner cases(n = 0, 1), int overflow
        //  check loops n -> 1 : --, neg after MOD
    }
#ifdef RAGH_A_VOID
    t2 = clock();
    cout << "\n\ntime taken: " << (t2 - t1) / (long double)CLOCKS_PER_SEC;
#endif
    return 0;
}

/*--------------- vi -> vll, vpii -> vpll, int -> ll --------------------------------------*/
