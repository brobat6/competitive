#include <bits/stdc++.h>
using namespace std;

int v[505][505];
int cnt[505*505];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    memset(cnt, 0, sizeof(cnt));
    int ini = 0;

    auto ins = [&](int i, int j) -> void {
        cnt[v[i][j]]--;
        if(cnt[v[i][j]] == 0) {
            ini--;
        }
    };
    auto rem = [&](int i, int j) -> void {
        cnt[v[i][j]]++;
        if(cnt[v[i][j]] == 1) {
            ini++;
        }
    };
    auto check = [&]() -> bool {
        return ini == k;
    };
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
            rem(i, j);
        }
    }
    if(ini <= k) {
        cout << k - ini;
        return 0;
    }
    for(int sz = 1; sz <= n; sz++) {
        for(int st = 0; st <= n - sz; st++) {
            for(int i = 0; i < sz; i++) {
                for(int j = 0; j < sz; j++) {
                    rem(st + i, j);
                }
            }
            if(check()) {
                cout << 1;
                return 0;
            }
            for(int j = sz; j < n; j++) {
                for(int i = 0; i < sz; i++) rem(st + i, j - sz);
                for(int i = 0; i < sz; i++) ins(st + i, j);
                if(check()) {
                    cout << 1;
                    return 0;
                }
            }
        }
    }
    cout << 2;
    return 0;
}