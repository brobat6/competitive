#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
	int n;
	vector <int> p, sz;

	DSU(int _n) : n(_n) {
		p.resize(n);
		sz.resize(n, 1);
		iota(p.begin(), p.end(), 0);
	}

	int find(int x) {
		if(x == p[x]) return x;
		return p[x] = find(p[x]);
	}

	pair<int, int> unite(int a, int b) {
		// return previous sizes.
		int c = find(a);
		int d = find(b);
		if(c != d) {
			if(sz[c] < sz[d]) swap(c, d);
			p[d] = c;
			pair<int, int> x = {sz[c], sz[d]};
			sz[c] += sz[d];
			return x;
		}
		return {-1, -1};
	}
};

class SegTree {
public:
	int n;
	vector <pair<int, int>> tree;

	SegTree(int _n) : n(_n) {
		tree.resize(4*n + 5, {0, 0});
	}

    pair<int, int> func(pair<int, int> a, pair<int, int> b) {
        return {a.first + b.first, a.second + b.second};
    }

	void update(int node, int start, int end, int pos, int val) {
		if(start == end) {
            tree[node].first += val;
            tree[node].second += start * val;
        } else {
            int mid = (start + end)/2;
            if(pos <= mid) {
                update(node*2, start, mid, pos, val);
            } else {
                update(node*2 + 1, mid + 1, end, pos, val);
            }
            tree[node] = func(tree[node*2], tree[node*2+1]);
        }
	}

    pair<int, int> query(int node, int start, int end, int k) {
        // sum of largest k elements.
        if(k < 0) return {0, 0};
        if(tree[node].first <= k) {
            return tree[node];
        }
        if(start == end) {
            return {k, start * k};
        }
        int mid = (start + end)/2;
        return func(query(node*2 + 1, mid + 1, end, k), query(node*2, start, mid, k - tree[node*2 + 1].first));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    DSU d(n);
    SegTree st(n + 1);
    st.update(1, 0, n, 1, n);
    for(int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if(type == 1) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            auto p = d.unite(x, y);
            if(p.first != -1) {
                st.update(1, 0, n, p.first, -1);
                st.update(1, 0, n, p.second, -1);
                st.update(1, 0, n, p.first + p.second, 1);
            }
        } else {
            int k;
            cin >> k;
            auto p = st.query(1, 0, n, k + 1);
            cout << p.second << '\n';
        }
    }
}