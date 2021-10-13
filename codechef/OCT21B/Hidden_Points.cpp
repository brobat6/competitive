#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const double eps = 1E-7;

struct pt {
    double x, y;
    int id;
};

struct cmp_x {
    bool operator()(const pt & a, const pt & b) const {
        return a.x < b.x || (abs(a.x == b.x)<eps && a.y < b.y);
    }
};

struct cmp_y {
    bool operator()(const pt & a, const pt & b) const {
        return a.y < b.y;
    }
};

int n;
vector<pt> a;

double mindist;
pair<int, int> best_pair;

void upd_ans(const pt & a, const pt & b) {
    double dist = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
    if (dist < mindist) {
        mindist = dist;
        best_pair = {a.id, b.id};
    }
}

vector<pt> t;

void rec(int l, int r) {
    if (r - l <= 3) {
        for (int i = l; i < r; ++i) {
            for (int j = i + 1; j < r; ++j) {
                upd_ans(a[i], a[j]);
            }
        }
        sort(a.begin() + l, a.begin() + r, cmp_y());
        return;
    }

    int m = (l + r) >> 1;
    double midx = a[m].x;
    rec(l, m);
    rec(m, r);

    merge(a.begin() + l, a.begin() + m, a.begin() + m, a.begin() + r, t.begin(), cmp_y());
    copy(t.begin(), t.begin() + r - l, a.begin() + l);

    int tsz = 0;
    for (int i = l; i < r; ++i) {
        if (abs(a[i].x - midx) < mindist) {
            for (int j = tsz - 1; j >= 0 && a[i].y - t[j].y < mindist; --j)
                upd_ans(a[i], t[j]);
            t[tsz++] = a[i];
        }
    }
}

void _print(pt f) {
    cout << f.x << " " << f.y << endl;
}

void interact() {
    cin >> n;
    a.clear(); 
    {
        pt f; f.x = 0; f.y = 0; f.id = 0;
        a.push_back(f);
        cout << "? " << 1 << " " << 2 << endl;
        int t; cin >> t;
        f.x = sqrt(t); f.y = 0; f.id = 1;
        a.push_back(f);
        cout << "? " << 1 << " " << 3 << endl;
        cin >> t;
        cout << "? " << 2 << " " << 3 << endl;
        int u; cin >> u;
        int c = a[1].x;
        f.x = (t - u + c*c)/(2.0*c);
        f.y = abs(sqrt(t - f.x*f.x));
        f.id = 2;
        a.push_back(f);
    }
    double p = a[1].x, q = a[2].x, r = a[2].y;
    forn(i, 4, n + 1) {
        int A, B, C;
        cout << "? " << 1 << " " << i << endl;
        cin >> A;
        cout << "? " << 2 << " " << i << endl;
        cin >> B;
        cout << "? " << 3 << " " << i << endl;
        cin >> C;
        pt f;
        f.x = (A - B + p*p)/(2.0*p);
        double y1;
        y1 = abs(sqrt(A - f.x*f.x));
        // cerr << abs((f.x-q)*(f.x-q) + (y1-r)*(y1-r) - C);
        if(abs((f.x-q)*(f.x-q) + (y1-r)*(y1-r) - C) < eps) {
            f.y = y1;
        }
        else f.y = -y1;
        f.id = i - 1;
        a.push_back(f);
    }
    // for(auto p : a) _print(p);
    t.resize(n);
    sort(a.begin(), a.end(), cmp_x());
    mindist = 1E20;
    rec(0, n);
    cout << setprecision(15) << mindist*mindist << endl;
}

void solve() {
    interact();
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}