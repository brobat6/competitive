#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n, a, b;
    priority_queue<int> pq;
    queue<int> q;
    cin >> n;
    forn(i, 0, n) {
        cin >> a;
        if(a == 1) {
            cin >> b;
            q.push(-b);
        }
        else if(a == 2) {
            if(pq.empty()) {
                cout << -q.front() << endl;
                q.pop();
            }
            else {
                cout << -pq.top() << endl;
                pq.pop();
            }
        }
        else {
            while(!q.empty()) {
                pq.push(q.front());
                q.pop();
            }
        }
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}