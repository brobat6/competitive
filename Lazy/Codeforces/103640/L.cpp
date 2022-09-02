#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2000100;
const int MOD = 1000000007;

int binpow(int a, int b) {
    int res = 1;
    while(b > 0) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res % MOD;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector <int> f(N), inv(N);
    f[0] = 1;
    inv[0] = 1;
    for(int i = 1; i < N; i++) {
        f[i] = f[i - 1] * i % MOD;
        inv[i] = binpow(f[i], MOD - 2);
    }

    auto COMB = [&](int n, int r) -> int {
        if(n < r) return 0;
        return f[n] * inv[r] % MOD * inv[n - r] % MOD;
    };

    int seat, easy, intro, extro;
    cin >> seat >> easy >> intro >> extro;

    // Make sure that easy + extro + intro == seat
    seat *= 2;
    if(easy > seat) easy = seat;
    if(easy + extro > seat) extro = seat - easy;
    if(easy + extro + intro > seat) intro = seat - easy - extro;
    seat /= 2;

    // 1. Process easygoing. Result of this should be a vector of {empty, single, probability}.
    vector<vector<int>> first; 
    for(int filled = 0; filled <= seat; filled++) {
        // assume number of "filled" seats is known.
        int single = easy - 2*filled;
        if(single < 0 || filled + single > seat) continue;
        int prob = COMB(seat, filled) * COMB(seat - filled, single) % MOD * binpow(2, single) % MOD * binpow(COMB(2*seat, easy), MOD - 2) % MOD;
        first.push_back({seat - filled - single, single, prob});
        // cout << filled << ' ' << single << ' ' << prob << '\n';
    }

    // 2. Process extroverted. Note that atmost one extroverted will be unhappy.
    // Result of this should be a vector of {empty, single_extro, single_easy, probability}.
    vector<vector<int>> second;
    for(auto p : first) {
        int left = extro;
        int temp = min(left, p[1]);
        p[1] -= temp;
        left -= temp;
        p[0] -= left/2;
        left %= 2;
        p[0] -= left % 2;
        second.push_back({p[0], left, p[1], p[2]});
    }

    // 3. Process introverted. Take two cases - the single_extro is satisfied, or not.
    int ans = 0;
    for(auto p : second) {
        if(p[1] == 0) {
            // no single extroverts.
            int happy = easy + extro;
            int happy_intro = 0;
            if(intro <= p[0]) {
                happy_intro = intro;
            } else if(intro <= p[0] + p[2]) {
                happy_intro = p[0];
            } else {
                int left_intro = intro - p[0] - p[2];
                happy_intro = p[0] - left_intro;
            }
            happy += happy_intro;
            ans += p[3] * happy % MOD;
            ans %= MOD;
        } else {
            int happy = easy + extro - 1;
            int happy_intro = 0;
            if(intro <= p[0]) {
                happy_intro = intro;
            } else {
                happy++; // extrovert happy. 
                int left_intro = intro - p[0] - p[1];
                happy_intro = p[0] - left_intro;
            }
            happy += happy_intro;
            ans += p[3] * happy % MOD;
            ans %= MOD;
        }
    }

    cout << ans;
    
    return 0;
}