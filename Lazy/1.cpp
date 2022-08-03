#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define forn(i, n) for(int i = 0; i < n; i++)
#define fora(i, a, n) for(int i = a; i < n; i++)
#define pb push_back
#define vi vector<int>
const int N = (int)2e5 + 10;
const int M = (int)1e9 + 7;




int32_t main(void)
{
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n, c, q;
        cin >> n >> c >> q;
        string s;
        cin >> s;
        // string str[c+1];
        int len[c+1];
        int red[c+1];
        red[0]=0;
        // str[0]=s;
        len[0]=s.length();
        for(int i=1; i<=c; i++)
        {
            int l, r;
            cin >> l >> r;
            int temp = r-l+1;
            len[i] = len[i-1]+temp;
            red[i] = len[i-1]-l+1;
        }
        forn(i, q)
        {
            int k;
            cin >> k;
            int ind=-1;
            for(int i=0; i<=c; i++)
            {
                if(k<=len[i])
                {
                    ind=i;
                    break;
                }
            }
            // int j = k-red[ind];
            int j=k;
            while(!(j>=1 && j<=len[0]))
            {
                j -= red[ind];
                ind--;
            }
            cout << s[j-1] << endl;
        }
    }
}