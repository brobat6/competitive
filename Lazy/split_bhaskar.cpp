#include <bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<int> sizeele;
int find(int a) {
    if (a == parent[a]) {
        return a;
    }
    return parent[a] = find(parent[a]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[a] = b;
        sizeele[b] += sizeele[a];
    }
}

int main() {
    int t, flag = 0, n;
    cin >> t;
    
    for (int _ = 0; _ < t; _++) {
        cin >> n;
        flag = 0;
        vector<int> freq;
        freq.resize(n);
        parent.clear();
        sizeele.clear();
        for(int i = 0; i < n; i++) {
            parent.push_back(i);
            sizeele.push_back(1);
        }
        
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            unite(x, y);
            freq[x]++;
            freq[y]++;
        }   

        for (int i = 0; i < n; i++) {
            if (freq[i] != 2) {
                cout << "NO" << endl;
                flag = 1;
                break;
            }
        }

        if (flag == 1) {
            continue;
        }

        for (int i = 0; i < n; i++) {
            if (sizeele[find(i)]%2) {
                cout << "NO" << endl;
                flag = 1;
                break;
            }
        }

        if (flag == 1) {
            continue;
        }
        cout << "YES" << endl;
    }

}