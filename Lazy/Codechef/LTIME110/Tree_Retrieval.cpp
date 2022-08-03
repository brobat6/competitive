#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vector deque

int q = 0;
int qq;

pair<int, int> ask(vector <int> v) {
    qq++;
    q++;
    assert(q <= 10000);
    cout << "? " << (int)v.size() << " ";
    for(auto i : v) cout << i << " ";
    cout << endl;
    pair<int, int> x;
    cin >> x.first;
    assert(x.first != -1);
    cin >> x.second;
    return x;
}

pair<int, int> ask(set <int> &v) {
    q++;
    qq++;
    assert(q <= 10000);
    cout << "? " << (int)v.size() << " ";
    for(auto i : v) cout << i << " ";
    cout << endl;
    pair<int, int> x;
    cin >> x.first;
    assert(x.first != -1);
    cin >> x.second;
    return x;
}

void output(vector<vector<int>> &adj, int n) {
    cout << "!" << endl;
    for(int i = 1; i <= n; i++) {
        for(auto j : adj[i]) {
            if(i < j) cout << i << " " << j << endl;
        }
    }
    int check;
    cin >> check;
    assert(check == 1);
}

void solve_task2(int n) {
    int root = -1;
    {
        vector <int> temp;
        for(int i = 1; i <= n; i++) {
            temp.push_back(i);
        }
        auto x = ask(temp);
        root = x.first;
    }
    vector<set<int>> parent(n + 1);
    vector<vector<int>> child(n + 1);
    for(int i = 1; i <= n; i++) {
        parent[i].insert(-i);
    }
    for(int i = 1; i <= n; i++) {
        if(i == root) continue;
        parent[i].insert(root);
        child[root].push_back(i);
        for(int j = i + 1; j <= n; j++) {
            if(j == i || j == root) continue;
            auto x = ask({i, j, root});
            if(x.second == i + j + root) continue;
            if(x.second == root + i) {
                parent[i].insert(j);
                child[j].push_back(i);
            } 
            if(x.second == root + j) {
                parent[j].insert(i);
                child[i].push_back(j);
            }
        }
    }

    // for(auto i : parent) {
    //     for(auto j : i) cout << j << " ";
    //     cout << endl;
    // }

    vector<vector<int>> adj(n + 1);
    vector <pair<int, int>> depth(n + 1);
    map <int, int> dd;
    depth[0].first = (int)1E9;
    for(int i = 1; i <= n; i++) {
        depth[i] = {(int)parent[i].size(), i};
        dd[i] = parent[i].size();
    }
    sort(depth.begin(), depth.end());
    // for(auto i : depth) cout << i.first << " " << i.second << endl;
    for(int i = 1; i < n; i++) {
        int curr = depth[i].second;
        int dp = depth[i].first;
        int par = -1;
        for(auto p : parent[curr]) {
            if(dd[p] == dp - 1) {
                par = p;
            }
        }
        assert(par != -1);
        adj[curr].push_back(par);
        adj[par].push_back(curr);
    }
    output(adj, n);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        qq = 0;

        // if(n <= 100) {
        //     solve_task2(n);
        //     continue;
        // }

        vector<vector<int>> adj(n + 1);

        auto unite = [&](int x, int y) -> void {
            assert(x >= 1 && x <= n);
            assert(y >= 1 && y <= n);
            adj[x].push_back(y);
            adj[y].push_back(x);
        };

        set <int> s;
        for(int i = 1; i <= n; i++) {
            s.insert(i);
        }
        pair<int, int> x;
        x = ask(s);
        int p1 = x.first;
        int p2 = x.second - x.first;
        s.erase(p1);
        s.erase(p2);
        if(p2 > n) {
            solve_task2(n);
            continue;
        }
        if(s.empty()) {
            unite(p1, p2);
        }
        bool pos = false;
        while(!s.empty()) {
            if((int)s.size() == 1) {
                unite(p1, *s.begin());
                unite(p2, *s.begin());
                s.clear();
                break;
            }
            x = ask(s);
            int l1 = x.first;
            int l2 = x.second - x.first;
            if(l2 > n) {
                pos = true;
                break;
            }
            s.erase(l1);
            s.erase(l2);
            x = ask({p1, l1, l2});
            int cl = (x.first == p1 ? x.second - x.first : x.first);
            if(cl > n) {
                pos = true;
                break;
            }
            if(l1 + l2 - cl > n) {
                pos = true;
                break;
            }
            unite(p2, cl);
            unite(l1 + l2 - cl, p1);
            p1 = l1;
            p2 = l2;
            if(s.empty()) {
                unite(p1, p2);
            }
            if(qq > n + 5) {
                pos = true;
                break;
            }
        }
        if(pos) {
            solve_task2(n);
            continue;
        }
        cout << "!" << endl;
        for(int i = 1; i <= n; i++) {
            for(auto j : adj[i]) {
                if(i < j) cout << i << " " << j << endl;
            }
        }
        int check;
        cin >> check;
        assert(check == 1);
    }
    
    return 0;
}