#include <bits/stdc++.h>
using namespace std;

int solution(int n, int k, vector<int> distance) {
    sort(distance.begin(), distance.end());
    vector <int> suff(n + 1, 0); // suffix maximum of cupcakes_eaten
    int ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        int end_index = upper_bound(distance.begin(), distance.end(), distance[i] + k) - distance.begin() - 1;
        int cupcakes_eaten = end_index - i + 1;
        ans = max(ans, suff[end_index + 1] + cupcakes_eaten);
        suff[i] = max(suff[i + 1], cupcakes_eaten);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << solution(n, k, v);
    
    return 0;
}