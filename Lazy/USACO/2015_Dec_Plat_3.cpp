#include <bits/stdc++.h>
using namespace std;

// KACTL Begins

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9;
struct Node
{
    Node *l = 0, *r = 0;
    int lo, hi, mset = inf, madd = 0, val = -inf;
    Node(int lo, int hi) : lo(lo), hi(hi) {} // Large interval of 􀀀inf
    Node(vi &v, int lo, int hi) : lo(lo), hi(hi)
    {
        if (lo + 1 < hi)
        {
            int mid = lo + (hi - lo) / 2;
            l = new Node(v, lo, mid);
            r = new Node(v, mid, hi);
            val = max(l->val, r->val);
        }
        else
            val = v[lo];
    }
    int query(int L, int R)
    {
        if (R <= lo || hi <= L)
            return -inf;
        if (L <= lo && hi <= R)
            return val;
        push();
        return max(l->query(L, R), r->query(L, R));
    }
    void set(int L, int R, int x)
    {
        if (R <= lo || hi <= L)
            return;
        if (L <= lo && hi <= R)
            mset = val = x, madd = 0;
        else
        {
            push(), l->set(L, R, x), r->set(L, R, x);
            val = max(l->val, r->val);
        }
    }
    void add(int L, int R, int x)
    {
        if (R <= lo || hi <= L)
            return;
        if (L <= lo && hi <= R)
        {
            if (mset != inf)
                mset += x;
            else
                madd += x;
            val += x;
        }
        else
        {
            push(), l->add(L, R, x), r->add(L, R, x);
            val = max(l->val, r->val);
        }
    }
    void push()
    {
        if (!l)
        {
            int mid = lo + (hi - lo) / 2;
            l = new Node(lo, mid);
            r = new Node(mid, hi);
        }
        if (mset != inf)
            l->set(lo, hi, mset), r->set(lo, hi, mset), mset = inf;
        else if (madd)
            l->add(lo, hi, madd), r->add(lo, hi, madd), madd = 0;
    }
};

template <bool VALS_EDGES>
struct HLD
{
    int N, tim = 0;
    vector<vi> adj;
    vi par, siz, depth, rt, pos;
    Node *tree;
    HLD(vector<vi> adj_)
        : N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1), depth(N),
          rt(N), pos(N), tree(new Node(0, N))
    {
        dfsSz(0);
        dfsHld(0);
    }
    void dfsSz(int v)
    {
        if (par[v] != -1)
            adj[v].erase(find(all(adj[v]), par[v]));
        for (int &u : adj[v])
        {
            par[u] = v, depth[u] = depth[v] + 1;
            dfsSz(u);
            siz[v] += siz[u];
            if (siz[u] > siz[adj[v][0]])
                swap(u, adj[v][0]);
        }
    }
    void dfsHld(int v)
    {
        pos[v] = tim++;
        for (int u : adj[v])
        {
            rt[u] = (u == adj[v][0] ? rt[v] : u);
            dfsHld(u);
        }
    }
    template <class B>
    void process(int u, int v, B op)
    {
        for (; rt[u] != rt[v]; v = par[rt[v]])
        {
            if (depth[rt[u]] > depth[rt[v]])
                swap(u, v);
            op(pos[rt[v]], pos[v] + 1);
        }
        if (depth[u] > depth[v])
            swap(u, v);
        op(pos[u] + VALS_EDGES, pos[v] + 1);
    }
    void modifyPath(int u, int v, int val)
    {
        process(u, v, [&](int l, int r)
                { tree->add(l, r, val); });
    }
    int queryPath(int u, int v)
    { // Modify depending on problem
        int res = -1e9;
        process(u, v, [&](int l, int r)
                { res = max(res, tree->query(l, r)); });
        return res;
    }
    int querySubtree(int v)
    { // modifySubtree is similar
        return tree->query(pos[v] + VALS_EDGES, pos[v] + siz[v]);
    }
};

// KACTL ends

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("maxflow.in", "r", stdin);
    // freopen("maxflow.out", "w", stdout);
    
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    HLD<false> hld(adj);
    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        hld.modifyPath(x, y, 1);
    }
    int ans = -inf;
    for(int i = 0; i < n; i++) {
        ans = max(ans, hld.queryPath(i, i));
        // cerr << hld.queryPath(i, i) + inf << " ";
    }
    cout << ans + inf;

    
    return 0;
}