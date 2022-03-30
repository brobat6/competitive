- [Faster unordered_map](#faster-unordered_map)
- [Random number Generator](#random-number-generator)
- [Ordered Set](#ordered-set)
- [Y_Combinator (Recursive Lambdas)](#y_combinator-recursive-lambdas)

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

# Ordered Set 

https://www.geeksforgeeks.org/ordered-set-gnu-c-pbds/

It is a Policy Based data structure. It works as a normal set, but can support two more operations:
1. find_by_order(k) : Returns an iterator to the kth element (counting from zero) in the set in O(Log N) time.
2. order_of_key(k) : Returns the number of items that are **strictly** smaller than the item K in O(Log N) time.

The following lines of code need to be added : 

```c++
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
```

It can also be used as an Ordered Set of pairs. Just change the definition to 
```c++
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>
```

Example of some operations : 
```c++
    ordered_set X;
    X.insert(1);
    X.insert(2);
    X.insert(4);
    X.insert(8);
    X.insert(16);

    cout<<*X.find_by_order(1)<<endl; // 2
    cout<<*X.find_by_order(2)<<endl; // 4
    cout<<*X.find_by_order(4)<<endl; // 16
    cout<<(end(X)==X.find_by_order(6))<<endl; // true

    cout<<X.order_of_key(-5)<<endl;  // 0
    cout<<X.order_of_key(1)<<endl;   // 0
    cout<<X.order_of_key(3)<<endl;   // 2
    cout<<X.order_of_key(4)<<endl;   // 2
    cout<<X.order_of_key(400)<<endl; // 5
```

# Y_Combinator (Recursive Lambdas)

The following lines of code let us use recursive lambdas in C++.

```c++
template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
```

Recursive lambdas can be used as follows: (Example of DFS)

```c++
int main() {
    auto DFS = y_combinator([&](auto self, int node) -> void {
        visited[node] = true;
        for(auto next : adj[node]) {
            if(visited[next]) continue;
            self(next);
        }
    });
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            DFS(i);
        }
    }
}
```