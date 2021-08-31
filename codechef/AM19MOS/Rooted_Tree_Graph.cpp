#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 100100
#define MOD 1000000007

int n, m;
bool visited[MAXN];
int parent[MAXN]; 
vector <int> adj[MAXN];
int size[MAXN];

struct Node {
    int first; // size
    int second; // id
};

bool comp(Node A, Node B) {
    if(A.first==B.first) return A.second < B.second;
    else return A.first < B.first;
}

void solve() {
    cin >> n >> m;
    forn(i, 0, n) {
        visited[i] = false;
        parent[i] = i;
        adj[i].clear();
        size[i] = 0;
    }
    int t1, t2;
    forn(i, 0, m) {
        cin >> t1 >> t2;
        t1--;
        t2--;
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
        size[t1]++;
        size[t2]++;
    }
    forn(i, 0, n) {
        Node pq[size[i]];
        forn(j, 0, size[i]) {
            pq[j].first = size[adj[i][j]];
            pq[j].second = adj[i][j];
        }
        sort(pq, pq + size[i], comp);
        visited[i] = true;
        forn(j, 0, size[i]) {
            auto x = pq[j];
            // x = {size[i], i}
            if(x.first < size[i] && parent[x.second]==x.second) parent[x.second] = i;
            else {
                if(!visited[x.second]) {
                    parent[i] = x.second;
                    break;
                }
            }
        }
        // forn(i, 0, n) cout << parent[i] << " ";
        // cout << endl;
    }
    forn(i, 0, n) {
        if(parent[i]==i) cout << 0 << " ";
        else cout << parent[i] + 1 << " ";
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t; cin >> t; while(t--)
{
    // Code goes here
    solve();
}
    return 0;
}