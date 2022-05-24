#include <bits/stdc++.h>
using namespace std;

#define frr(i,a,b) for(int i=a;i<=b;i++)
#define test(t) int t; cin >> t; frr(tno,1,t)
#define int long long
#define endl '\n'

const int N = 1000000007;
const int INF = 1000000000000000000;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input12.txt","r",stdin);
    // freopen("ans12.txt","w",stdout);
    test(t) {
        int n,a,b;
        cin >> n >> a >> b;
        a--,b--;
        int p[n]={};
        set<int> cur;
        for (int t1=0;t1<n;t1++) {
            cin >> p[t1];
            cur.insert(t1);
        }
        queue<int> q;
        q.push(a);
        int vis[n]={};
        vis[a]=1;
        int depth[n]={};
        depth[a]=0;
        int ck=0;
        while (!q.empty()) {
            int sp=q.front();
            q.pop();
            int val1=sp-p[sp],val2=sp+p[sp];
            auto it=cur.lower_bound(val1);
            auto next=it;
            while (it!=cur.end() && (*it)<=val2) {
                val1=*it+1;
                next=it;
                next++;
                if (!vis[*it] && ((*it+p[*it])>=sp && (*it-p[*it])<=sp)) {
                    vis[*it]=1;
                    depth[*it]=depth[sp]+1;
                    q.push(*it);
                    if (*it==b) {
                        ck=1;
                        break;
                    }
                    cur.erase(*it);
                }
                it=next;
            }
            if (ck) {
                break;
            }
        }
        cout << depth[b] << endl;
    }
    return 0;
}