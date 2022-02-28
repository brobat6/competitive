- [Faster unordered_map](#faster-unordered_map)
- [Random number Generator](#random-number-generator)

# Faster unordered_map

The following lines of code let us use a faster unordered_map in C++. 

```c++
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef cc_hash_table<int, int, hash<int>> ht;
```

# Random number Generator

The following lines of code let us add a high quality random number generator in C++.

```c++
#include<bits/stdc++.h>
using namespace std;

int main() {
    mt19937 rng_32(chrono::steady_clock::now().time_since_epoch().count()); // 32 bit random nos
    mt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count()); // 64 bit random nos
    cout << rng(); // Generating a random no
    vector <int> arr;
    shuffle(arr.begin(), arr.end(), rng); // Randomly shuffling a permutation
}
```