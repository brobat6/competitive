#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        cout << "F";
    }
    
    return 0;
}


/*
Examples:

1000, 0100 -> 1
1000, 0100, 0010 -> 1
1000, 1000, 0100, 0010 -> 2

1000100, 0000010, 0000001 -> 1

100100, 100100, 100100, 000010, 000001 -> 1

Ans is definitely <= number of components i.e. <= 30.
For any 2-bit or higher component --> Either NO CHANGE or SUBTRACT ANY 1 VALUE
For any 1-bit component --> Either ADD 1 VALUE or (SUBTRACT 1 + ADD 1). [For singleton component, just subtract 1].
Never change any odd values.

So first --> Add 1 to any singleton components (check in O(N^2)) and to any 0s.

Now, for any 1-bit component --> Just add 1 anywhere.

Now run DSU again to get connected components. All remaining components are multi-bit. (i.e. connected by 2 or more bits)
Now we have to subtract 1 from minimum number of components.
Do this in O(2^n)? Since number of components <= 15... Find out if all 15 can be connected by minimum number of subtractions!

Heavy implementation.
*/