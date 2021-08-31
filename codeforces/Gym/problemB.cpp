#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define MAXN 200100
#define MOD 1000000007

vector <pair<ll, ll>> v;
ll k;
vector <ll> ans;
vector <ll> squares;

void FindDivisors(ll n) {
    for(ll i=1; i<=sqrt(n); i++) {
        if(n%i==0) {
            if(n/i==i) v.push_back({i, i});
            else v.push_back({i, n/i});
        }
    }
}

void CalcSquares() {
    for(ll i=1; i<=sqrt(1000000000); i++) {
        squares.push_back(i*i);
        squares.push_back(-(i*i));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // ll t; cin >> t; while(t--)
{
    // Code goes here
    cin >> k;
    FindDivisors(k);
    for(auto i : v) {
        if(i.second - i.first == 0) continue;
        if((i.second - i.first)%2==0) {
            ll b = (i.first + i.second)/2;
            ll a = abs((i.second - i.first)/2);
            if((a*a + k) == (b*b)) {
                ans.push_back(a*a);
                ans.push_back(-(b*b));
            }
        }
    }
    CalcSquares();
    ll x = squares.size();
    sort(squares.begin(), squares.end());
    ll l = 0, r = 31622;
    while(r<x) {
        if(squares[l]>0) break;
        if(l==r) r++;
        else if(squares[r] - squares[l] == k) {
            ans.push_back(squares[l]);
            l++;
        }
        else if(squares[r] - squares[l] > k) {
            l++;
        }
        else r++;
    }
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for(auto i: ans) cout << i << " ";
}
    return 0;
}