#include <iostream>
using namespace std;
#define MAXN 100100

int n;
int st[2*MAXN];

void build() {
    for(int i=n-1; i>0; i--) st[i] = st[i<<1] + st[i<<1|1]; 
}

void modify(int p, int value) {
    for(st[p += n] = value; p>1; p>>=1) st[p>>1] = st[p] + st[p^1];
}

int query(int l, int r) {
    int res = 0;
    for(l += n, r += n; l < r; l>>=1, r>>=1) {
        if(l&1) res += st[l++];
        if(r&1) res += st[--r];
    }
    return res;
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) cin >> st[n+i];
    build();
}