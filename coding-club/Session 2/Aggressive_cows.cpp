// https://www.spoj.com/problems/AGGRCOW/
 
#include <bits/stdc++.h>

using namespace std;

long long n,c,temp;
vector <long long> dis;

bool check(long long k) {
    //return true if yes
    long long count = 1;
    long prev = dis[0];
    for (long long i=1; i<n; i++) {
        if (dis[i] - prev >= k) {
            count++;
            prev = dis[i];
        }
    }
    return (count >= c);
}

long long binary(long long left, long long right) {
    if (right - left <= 1) {
        if (check(right)==1) {
            return right;
        }
        else {
            return left;
        }
    }
    long long mid = (left + right) / 2;
    if (check(mid)==1) {
        return binary(mid,right);
    }
    else {
        return binary(left,mid-1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    long long t;
    cin >> t;
    while (t--) {
        cin >> n >> c;
        for (long long i = 0; i<n; i++) {
            cin >> temp;
            dis.push_back(temp);
        }
        sort(dis.begin(),dis.end());
        long long ans = binary(0,1000000000);
        cout << ans << endl;
        dis.clear();
    }
    return 0;
}
