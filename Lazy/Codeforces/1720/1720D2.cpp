#include <bits/stdc++.h>
using namespace std;

const int M = 30;

struct Trie {
    Trie* bit[4];
    int dp = 1;
};
Trie* root;

void insert(int node, int index, int value) {
    Trie* temp = root;
    for(int i = 0; i < 31; i++) {
        int b1 = (node >> (30 - i)) & 1;
        int b2 = (index >> (30 - i)) & 1;
        int b = (b1<<1)|b2;
        if(!temp->bit[b]) {
            temp->bit[b] = new Trie();
        }
        temp->dp = max(temp->dp, value);
        temp = temp->bit[b];
    }
    temp->dp = value;
}

int query(int node, int index) {
    Trie* temp = root;
    int ans = 0;
    for(int i = 0; i < 31; i++) {
        int b1 = (node >> (30 - i)) & 1;
        int b2 = (index >> (30 - i)) & 1;
        int b = (b1<<1)|b2;
        map<int, int> nx; nx[0] = 1; 
        nx[1] = 3; nx[3] = 2; nx[2] = 0;
        if(temp->bit[nx[b]] != nullptr) {
            // Smaller!!!
            ans = max(ans, temp->bit[nx[b]]->dp);
        }
        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        root = new Trie();
        int n;
        cin >> n;
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            int x = query(v[i], i);
            insert(v[i], i, x + 1);
        }
        cout << (root->dp) << '\n';
    }
    
    return 0;
}