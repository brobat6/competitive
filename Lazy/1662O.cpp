#include <bits/stdc++.h>
using namespace std;
#define int long long

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

const int XX = 360;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int r = 22;
        vector<vector<int>> circ, strt;
        for(int i = 0; i < n; i++) {
            char a; int b, c, d;
            cin >> a >> b >> c >> d;
            if(a == 'C') {
                circ.push_back({b, c, d});
            } else {
                strt.push_back({b, c, d});
            }
        }        
        vector<vector<int>> ang(r + 1, vector<int>(XX, 1)); // is the particular angle an opening or not? 
        for(auto c : circ) {
            int r = c[0];
            int o1 = c[1];
            int o2 = c[2];
            if(o2 < o1) o2 += XX;
            for(int o = o1; o < o2; o++) {
                ang[r][o % XX] = 0;
            }
        }
        // for(int i = 1; i <= r; i++) {
        //     cout << "r = " << i << ": ";
        //     for(int j = 0; j < 360; j++) {
        //         if(ang[i][j]) cout << j << " ";
        //     }
        //     cout << '\n';
        // }

        vector<vector<int>> st(r + 1); // the angles at which straight lines are present.
        for(auto s : strt) {
            int r1 = s[0];
            int r2 = s[1];
            int o = s[2];
            for(int i = r1; i < r2; i++) {
                st[i].push_back(o);
            }
        }
        for(int i = 0; i <= r; i++) {
            sort(st[i].begin(), st[i].end());
            int c = st[i].size();
            if(c == 0) st[i].push_back(XX);
            else st[i].push_back(st[i][0] + XX);
        }
        // cout << r << '\n';
        // for(int i = 1; i <= r; i++) {
        //     cout << "r = " << i << '\n';
        //     for(auto j : st[i]) cout << j << " ";
        //     cout << '\n';
        // }

        vector<vector<bool>> marked(r + 1, vector<bool>(XX, false));
        for(int i = 0; i < XX; i++) {
            if(ang[r][i] == 1) marked[r][i] = true;
        }

        for(int i = r - 1; i >= 1; i--) {
            for(int o1 = 0; o1 < XX; o1++) {
                // this is the inner angle.
                if(ang[i][o1] == 0) continue;
                for(int o2 = 0; o2 < XX; o2++) {
                    // the outer angle
                    if(ang[i + 1][o2] == 0 || marked[i + 1][o2] == false || marked[i][o1] == true) continue;
                    // now we want to check if there is a path between o1 and o2. 
                    int a = *upper_bound(st[i].begin(), st[i].end(), o1);
                    int b = *upper_bound(st[i].begin(), st[i].end(), o2);
                    b %= XX; a %= XX;
                    marked[i][o1] = (a == b);
                }
            }
        }

        bool pos = false;
        for(int i = 0; i < XX; i++) {
            if(marked[1][i]) pos = true;
        }
        cout << (pos ? "YES" : "NO") << '\n';
    }
    
    return 0;
}