- [Binary Search](#binary-search)
- [GCD](#gcd)
- [XOR Hashing](#xor-hashing)
  - [Questions](#questions)

# Binary Search

The following code can be used to find the maximum x satisfying a given condition. 
- Left : The lower bound of the search space
- B : The length of the search space (Halves at each step)
- check(x) : Returns true if x satisfies the given condition, false otherwise.
```c++
bool check(int x) {
    
}

int left = 0;
for(int b = 1E8; b > 0; b >>= 1) { 
    if(check(left + b)) {
        left += b;
    }
}
```

# GCD

```c++
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}
```

# XOR Hashing

## Questions
1. https://www.codechef.com/problems/VLD (not sure if XOR hashing or not)
2. https://codeforces.com/problemset/problem/1418/G
3. 