//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    cin >> t;
while(t--) {
    int n, m;
    cin >> n >> m;
    vector <int> ap;
    vector <int> an;
    vector <int> bp;
    vector <int> bn;
    int temp;
    for(int i=0; i<n; i++) {
        cin >> temp;
        if(temp>0) ap.push_back(temp);
        if(temp<0) an.push_back(temp);
    }
    for(int i=0; i<m; i++) {
        cin >> temp;
        if(temp>0) bp.push_back(temp);
        if(temp<0) bn.push_back(temp);        
    }
    
}
    return 0;
}
