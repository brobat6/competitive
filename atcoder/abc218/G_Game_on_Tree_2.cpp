#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 100100;
const int MOD = 1000000007;

/*
BINARY SEARCH.
For a given value x -
Check, in O(N), if it is possible to have median >= x.
If number of turns is odd, then Greater values must be more than Smaller values.
If number of turns is even, we must store the greatest value less than x and smallest value >= x also [as we will take
their average for median in the case than num(greater values) == num(smaller values).
We want to maximise the number of greater values at each step. In case number is equal for two choices, we 
want to choose the choice with greater "smallest value >= x".
The enemy will try to do the opposite.
*/

int n, t1, t2;
vector <int> adj[MAXN];
int arr[MAXN];
int dist[MAXN];
vector<int> med[MAXN]; // {num(greater), smallest greater, biggest smaller, num(smaller)}

bool compMax(vector<int> &A, vector<int> &B) {
    if(A[0]-A[3]==B[0]-B[3]) {
        int a = A[1], b = A[2], c = B[1], d = B[2];
        if(a==MOD) a = b;
        if(b==0) b = a;
        if(c==MOD) c = d;
        if(d==0) d = c;
        return (a+b)/2 > (c+d)/2;
    }
    return A[0]-A[3] > B[0]-B[3];
}

bool compMin(vector<int> &A, vector<int> &B) {
    if(A[3]-A[0]==B[3]-B[0]) {
        int a = A[1], b = A[2], c = B[1], d = B[2];
        if(a==MOD) a = b;
        if(b==0) b = a;
        if(c==MOD) c = d;
        if(d==0) d = c;
        return (a+b)/2 < (c+d)/2;
    }
    return A[3]-A[0] > B[3]-B[0];
}

void dfs(int node, int prev, int x) {
    vector<vector<int>> temp;
    for(auto next : adj[node]) {
        if(next == prev) continue;
        dfs(next, node, x);
        temp.push_back(med[next]);
    }
    // If dist%2 is 0, we want to maximise. dist%2 is 1 --> minimize.
    sort(temp.begin(), temp.end(), dist[node]%2 ? compMin : compMax);
    if(temp.size() > 0) med[node] = temp[0];
    else med[node] = {0, MOD, 0, 0};
    if(arr[node] >= x) {
        med[node][0]++;
        med[node][1] = min(med[node][1], arr[node]);
    }
    else {
        med[node][3]++;
        med[node][2] = max(med[node][2], arr[node]);
    }
}

bool check(int x) {
    dfs(0, 0, x);
    int a = med[0][0], b = med[0][3], c = med[0][1], d = med[0][2];
    if(a == b) {
        return (c+d)/2 >= x;
    }
    return a > b;
}

int binary_search(int left, int right) {
    int ans = -1;
    while(left <= right) {
        int mid = (left + right)/2;
        if(check(mid)) {
            left = mid + 1;
            ans = mid;
        }
        else {
            right = mid - 1;
        }
    }
    return ans;
}

void bfs(int start) {
    memset(dist, -1, sizeof(dist));
    dist[start] = 0;
    queue <int> q;
    q.push(start);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto next : adj[curr]) {
            if(dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
}

void solve() {
    cin >> n;
    forn(i, 0, n) cin >> arr[i];
    forn(i, 0, n-1) {
        cin >> t1 >> t2;
        adj[--t1].push_back(--t2);
        adj[t2].push_back(t1);
    }
    bfs(0);
    cout << binary_search(2, 1E9);
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}