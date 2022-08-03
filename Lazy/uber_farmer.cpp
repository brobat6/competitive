#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1E9 + 7;

class SegTree {
public:
    vector <pair<int, int>> tree;

    SegTree(int n) {
        tree.resize(n * 4, {INF, 0});
    }

    pair<int, int> func(pair<int, int> a, pair<int, int> b) {
        if(a.first < b.first) return a;
        return b;
    }

    void update(int node, int start, int end, int pos, int val) {
        if(start == end) {
            tree[node] = {val, start};
        } else {
            int mid = (start + end)/2;
            if(pos <= mid) {
                update(node*2, start, mid, pos, val);
            } else {
                update(node*2 + 1, mid + 1, end, pos, val);
            }
            tree[node] = func(tree[node*2], tree[node*2 + 1]);
        }
    }

    pair<int, int> query(int node, int start, int end, int l, int r) {
        if(l > r) {
            return {INF, 0};
        }
        if(l == start && r == end) {
            return tree[node];
        }
        int mid = (start + end)/2;
        return func(query(node*2, start, mid, l, min(mid, r)), query(node*2 + 1, mid + 1, end, max(l, mid + 1), r));
    }
};

vector <int> solution(int n, int k, vector<vector<int>> events) {
    SegTree st(n);
    vector <int> sol;
    for(auto e : events) {
        if(e[0] == 1) {
            st.update(1, 0, n - 1, e[1], e[2]);
        } else {
            int ans = 0;
            while(true) {
                pair<int, int> q = st.query(1, 0, n - 1, e[1], e[2] - 1);
                if(q.first <= e[3]) {
                    ans++;
                    st.update(1, 0, n - 1, q.second, INF);
                } else break;
            }
            sol.push_back(ans);
        }
    }
    return sol;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<vector<int>> events(k);
    for(int i = 0; i < k; i++) {
        int x;
        cin >> x;
        if(x == 1) {
            int a, b;
            cin >> a >> b;
            events[i] = {x, a, b};
        } else {
            int a, b, c;
            cin >> a >> b >> c;
            events[i] = {x, a, b, c};
        }
    }
    auto ans = solution(n, k, events);
    for(auto i : ans) cout << i << " ";
    
    return 0;
}