#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 120
#define MOD 1000000007

const double PI = acos(-1);
static inline double angle(double x1, double y1, double x2, double y2){
	return atan2(x1*y2 - y1*x2, x1*x2 + y1*y2);
}

double X1,X2,Y1,Y2;
double temp;
vector<int> adj[MAXN];

bool inside(vector<pair<int, int>> polyg, pair<int, int> point){
	double ang = 0;
	double x = point.first, y = point.second;
	int n = polyg.size();
	for(int i = 0; i < n-1; i++){
		X1 = polyg[i].first - x;
		X2 = polyg[i+1].first - x;
		Y1 = polyg[i].second - y;
		Y2 = polyg[i+1].second - y;
		temp = angle(X1,Y1,X2,Y2);
		if(abs(temp - PI) < 0.000000001) return false;
		ang += temp;
		//cout << ang << endl;
	}
	X1 = polyg[n-1].first - x;
	X2 = polyg[0].first - x;
	Y1 = polyg[n-1].second - y;
	Y2 = polyg[0].second - y;
	ang += angle(X1,Y1,X2,Y2);
	//cout << ang << endl;
	if(abs(ang - 2*PI) < 0.00000001) return true;
	else return false;
}

bool checkinside(vector<pair<int, int>> p1, vector<pair<int, int>> p2){
	bool b1 = true;
	for(auto &p : p1){
		if(!inside(p2, p)){
			//cout << "~~" << endl;
			b1 = false;
			break;
		}
	}
	return b1;
}

bool allEmpty(int n) {
    forn(i, 0, n) {
        if(adj[i].size()!=0) return false;
    }
    return true;
}

int maximum_matching(int n) {
    vector<int> level(n), mate(2*n, -1);
    function<bool(void)> levelize = [&]() { // BFS
    queue<int> Q;
    for (int u = 0; u < n; ++u) {
        level[u] = -1;
        if (mate[u] < 0)
        level[u] = 0, Q.push(u);
    }
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int w: adj[u]) {
        int v = mate[w];
        if (v < 0) return true;
        if (level[v] < 0) {
            level[v] = level[u] + 1; Q.push(v);
        }
        }
    }
    return false;
    };
    function<bool(int)> augment = [&](int u) { // DFS
    for (int w: adj[u]) {
        int v = mate[w];
        if (v < 0 || (level[v] > level[u] && augment(v))) {
        mate[u] = w;
        mate[w] = u;
        return true;
        }
    }
    return false;
    };
    int match = 0;
    while (levelize()) 
    for (int u = 0; u < n; ++u) 
        if (mate[u] < 0 && augment(u)) 
        ++match;
    return match;
}

int w, x, y, z;

void solve() {
    int N;
	cin >> N;
	vector<pair<int, int>> polygons[N];
	for(int i = 0; i < N; i++){
		cin >> w;
		polygons[i].resize(w);
		for(int j = 0; j < w; j++){
			cin >> polygons[i][j].first >> polygons[i][j].second;
		}
	}
	forn(i, 0, MAXN) adj[i].clear();
	bool adjacent[N][N] = {false};
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(checkinside(polygons[j],polygons[i])){
				adj[i].push_back(j);
				adj[j].push_back(i);
				adjacent[i][j] = adjacent[j][i] = true;
			}
		}
	}
    cout << N - maximum_matching(N) << endl;
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