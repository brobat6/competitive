// http://www.usaco.org/index.php?page=viewproblem2&cpid=835

#include <bits/stdc++.h>

using namespace std;

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    // cout.precision(numeric_limits<double>::max_digits10);
    freopen("x.txt","r",stdin);
    freopen("x_out.txt","w",stdout);
    long long n,temp;
    cin >> n;
    vector <long long> v;
    for(long long i=0; i<n; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    int count = 0,xx=0;
    sort(v.begin(),v.end());
    for(long long i=n-1; i>=0; i--) {
        if(v[i]<count) {
            cout << count;
            xx=1;
            break;
        }
        count++;
    }
    if(xx==0) cout<<n;
    cout << "x";
    return 0;
}

// #include <iostream>
// #include <fstream>
// #include <algorithm>
// using namespace std;
 
// int N, W[100000];
 
// int main(void)
// {
//   ifstream fin("lemonade.in");
//   ofstream fout("lemonade.out");
 
//   fin >> N;
//   for (int i=0; i<N; i++) fin >> W[i];
 
//   sort(W,W+N);
  
//   int i, num_in_line=0;
//   for (i=N-1; i>=0; i--) {
//     if (W[i] < num_in_line) break;
//     num_in_line++;
//   }
 
//   fout << num_in_line << "\n";
 
//   return 0;
// }