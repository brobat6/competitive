#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    map<int, int> occ; // m[mod] --> {when it first came}
    vector <int> seq;
    int curr = 0;
    if(k < 2 * n) {
        for(int i = 0; i < k; i++) {
            curr += (v[curr % n]);
        }
        cout << curr;
        return 0;
    }
    occ[0] = 0;
    int first = 0;
    int second = 0;
    seq.push_back(0);
    for(int i = 0; i < 2*n; i++) {
        curr += (v[curr % n]);
        seq.push_back(curr);
        if(occ.find(curr % n) != occ.end()) {
            first = occ[curr % n];
            second = i + 1;
            break;
        }
        occ[curr % n] = i + 1;
    }
    int repeat_length = second - first;
    int repeat_sum = seq[second] - seq[second - repeat_length];
    int ans = seq[(int)seq.size() - 1];
    int done_ops = second;
    // cout << repeat_length << " " << repeat_sum << " " << done_ops << endl;
    k -= done_ops;
    int repeats = k / repeat_length;
    k -= (k / repeat_length) * repeat_length;
    ans += (repeat_sum * repeats);
    for(int i = 0; i < k; i++) {
        ans += (v[ans % n]);
    }
    cout << ans;

    return 0;
}