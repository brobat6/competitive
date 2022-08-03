#include <bits/stdc++.h>
using namespace std;
// #define int long long

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef cc_hash_table<int, int, hash<int>> ht;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    
    long long n, m;
    cin >> n >> m;
    bool neg = false;
    if(m < 0) {
        neg = true;
        m *= -1;
    }
    map<int, bool> done;

    ht s;
    vector <int> v;

    auto check = [&](int x) -> bool {
        if(done.find(x) != done.end()) return false;
        if(s[x] == 1) return false;
        for(auto i : v) {
            int a = x;
            int b = i;
            if(a > b) swap(a, b);
            vector <int> w;
            w.push_back(a + 2*(b - a));
            w.push_back(b - 2*(b - a));
            if((b - a) % 2 == 0) {
                w.push_back(a + (b - a)/2);
            }
            for(auto j : w) {
                if(s[j] == 1) {
                    done[x] = true;
                    return false;
                }
            }
        }
        return true;
    };

    s[0] = 1; 
    v.push_back(0);

    long long sum = m;

    for(int i = min((long long)1E7, sum); i >= 1; i--) {
        // if i satisfies all values, push it in
        if(i > sum) continue;
        if(check(i)) {
            s[i] = 1;
            v.push_back(i);
            sum -= i;
        }
        if(sum == 0) break;
    }
    // for(auto i : v) cout << i << " ";

    v.erase(v.begin());
    s[0] = 0;

    int rem = n - (int)v.size();

    if(rem == 1) {
        v.push_back(0);
        s[0] = 1;
    } else {
        if(rem % 2 == 1) {
            int first = -1;
            for(int i = 1; i <= (int)1E7; i++) {
                if(check(i)) {
                    first = i;
                    break;
                }
            }
            v.push_back(first);
            s[first] = 1;
            while(true) {
                int i = (rng() % (int)(1E7)) + 1;
                if(check(i) && check(-i-first)) {
                    v.push_back(i);
                    v.push_back(-i-first);
                    s[i] = 1;
                    s[-i-first] = 1;
                    rem -= 3;
                    break;
                }
            }
        }
        for(int i = 1; i <= 10000000; i += rng() % 7) {
            if(check(i) && check(-i)) {
                v.push_back(i);
                v.push_back(-i);
                s[i] = 1;
                s[-i] = 1;
                rem -= 2;
            }
            if(rem == 0) break;
        }
        cerr << rem;
    }
    for(auto i : v) {
        if(neg) cout << -i << " ";
        else cout << i << " ";
    }
    
    return 0;
}