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

void func(int n) {
    // From adjaceny list, find the minimum number of DELETIONS to make all vertices distinct.
    // One deletion - O(n)
    // Max deletions - n
    // Worst case - O(n^2)
    // How to check if all vertices are distinct? --> their adjacency list is empty
    int k = n;
    while(true) {
        if(allEmpty(n)) {
            cout << k << endl;
            return;
        }
        int max_size = 0;
        int max_index = 0;
        forn(i, 0, n) {
            if(adj[i].size() > max_size) {
                max_size = adj[i].size();
                max_index = i;
            }
        }
        k--;
        // if(k==1) {
        //     cout << "Lol" << endl;
        //     break;
        // }
        adj[max_index].clear();
        forn(i, 0, n) {
            if(adj[i].size()==0) continue;
            int temp_index = -1;
            forn(j, 0, adj[i].size()) {
                if(adj[i][j] == max_index) temp_index = j;
            }
            if(temp_index!=-1) {
                adj[i].erase(adj[i].begin() + temp_index);
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector <pair<int, int>> points[n];
    forn(i, 0, n) {
        int v; // The number of vertices in the polygon.
        cin >> v;
        forn(j, 0, v) {
            int t1, t2;
            cin >> t1 >> t2;
            points[i].push_back({t1, t2});
        }
    }
    forn(i, 0, MAXN) adj[i].clear();
    forn(i, 0, n) {
        forn(j, 0, i) {
            // Now we want to compare Polygons i and j.
            // 1. Check if i is inside j.
            bool ij = checkinside(points[i], points[j]);
            // 2. Check if j is inside i.
            bool ji = checkinside(points[j], points[i]);
            if(ij || ji) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    // forn(i, 0, n) {
    //     cout << i << ": ";
    //     for(auto j : adj[i]) cout << j << " ";
    //     cout << endl;
    // }
    func(n);
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