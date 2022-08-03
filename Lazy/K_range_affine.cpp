#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;

class SegTree {
    int n;
    struct Node {
        int l, r;
        int sum;
        pair <int, int> lazy;
        Node() {
            l = r = sum = 0;
            lazy = {1, 0};
        }
    };
    vector <Node> arr;
    
    SegTree(int _n) : n(_n) {
        arr.resize(n<<2);
    }

    void pull(Node &ans, Node left, Node right) {
        ans.sum = (left.sum + right.sum) % MOD;
        ans.l = left.l;
        ans.r = right.r;
    }

    void pull(int ind) {
        pull(arr[ind], arr[ind<<1], arr[ind<<1|1]);
    }

    void push(int ind) {
        if(arr[ind].lazy.second == 0) return;
        for(int i = 0; i < 2; i++) {
            arr[ind<<1|i].sum = arr[ind<<1|i].sum * arr[ind].lazy.first % MOD;
            arr[ind<<1|i].sum = (arr[ind<<1|i].sum + ((arr[ind<<1|i].r - arr[ind<<1|i].l + 1)*arr[ind].lazy.second)) % MOD;
            arr[ind<<1|i].lazy = {arr[ind<<1|i].lazy.first * arr[ind].lazy.first % MOD, (arr[ind<<1|i].lazy.second * arr[ind].lazy.first + arr[ind].lazy.second) % MOD};
        }
        arr[ind].lazy = {1, 0};
    }

    
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;

    
    return 0;
}