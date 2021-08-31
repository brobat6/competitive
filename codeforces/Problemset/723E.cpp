#include <bits/stdc++.h>
using namespace std;
int t, n, m, u, v;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        std::vector<set<int>> g(n + 1);
        while (m--)
        {
            cin >> u >> v;
            g[u].insert(v), g[v].insert(u);
        }
        for (int i = 1; i <= n; i++)
            if (g[i].size() & 1)
                g[i].insert(0), g[0].insert(i);
        cout << n - g[0].size() << "\n";
        for (int i = 0; i <= n; i++)
        {
            while (!g[i].empty())
            {
                v = *g[i].begin();
                g[i].erase(v), g[v].erase(i);
                if (i && v)
                    cout << i << " " << v << "\n";
                i = v;
            }
        }
    }
}