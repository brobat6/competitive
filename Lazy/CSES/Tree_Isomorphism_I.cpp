#include <bits/stdc++.h>
using namespace std;

class EncodeRootedTree {
public:
    int n;
    deque<char> tree_code; // will contain the encoding of the rooted tree.
    vector<vector<int>> adj;
    vector<deque<char>> code;

    EncodeRootedTree(vector<vector<int>> _adj, int root = 0) {
        adj = _adj;
        n = adj.size();
        code.resize(n);
        tree_code = code[dfs(root, root)];
    }

    int dfs(int node, int prev) {
        vector <int> p;
        p.push_back(node);
        for(auto next : adj[node]) {
            if(next != prev) p.push_back(dfs(next, node));
        }
        sort(p.begin(), p.end(), [&](int a, int b) {
            return (int)code[a].size() > (int)code[b].size();
        });
        vector<deque<char>> c;
        for(auto i : p) {
            if(i != p.front()) {
                c.push_back(code[i]);
            }
        }
        sort(c.begin(), c.end());
        int bigger = 0;
        for(int i = 0; i < (int)c.size(); i++) {
            auto it = code[p.front()].begin();
            bool smaller = true;
            for(int j = 0; j < (int)c[i].size(); j++) {
                if(c[i][j] < (*it)) break;
                if(c[i][j] > (*it)) {
                    smaller = false;
                    break;
                }
                it++;
            }
            if(smaller) bigger++;
        }
        for(int i = bigger - 1; i >= 0; i--) {
            // These are all smaller than heaviest child. Push_front.
            reverse(c[i].begin(), c[i].end());
            for(auto j : c[i]) code[p.front()].push_front(j);
        }
        for(int i = bigger; i < (int)c.size(); i++) {
            for(auto j : c[i]) code[p.front()].push_back(j);
        }
        code[p.front()].push_front('1');
        code[p.front()].push_back('0');
        return p.front();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n), b(n);
        for(int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for(int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            b[x].push_back(y);
            b[y].push_back(x);
        }
        EncodeRootedTree A(a);
        EncodeRootedTree B(b);
        cout << (A.tree_code == B.tree_code ? "YES" : "NO") << '\n';
    }
    
    return 0;
}