- [Trie](#trie)
  - [Resources:](#resources)
  - [Problems:](#problems)
  - [Trie implementation using 2D Array](#trie-implementation-using-2d-array)
  - [Trie - Implementation (Better)](#trie---implementation-better)
- [Segment Tree](#segment-tree)
  - [Resources:](#resources-1)
  - [Template (Basic)](#template-basic)
- [Fenwick Tree](#fenwick-tree)

# Trie

## Resources:

1. https://leetcode.com/problems/implement-trie-prefix-tree/solution/
2. https://codeforces.com/blog/entry/15729
3. https://leetcode.com/explore/learn/card/trie/ 

## Problems:

1. https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3ff3#problem. Solution - https://codingcompetitions.withgoogle.com/kickstart/submissions/000000000019ffc7/00000000005a8fe0
2.  https://codeforces.com/contest/1625/problem/D
3.  https://codeforces.com/problemset/problem/706/D
4.  https://www.codechef.com/JAN15/problems/XRQRS
5.  https://codeforces.com/contest/456/problem/D

Trie is quite useful in XOR related queries. Say we are given a number X (per query) and an array of numbers A and we want to find A[i] such that x^A[i] is maximum. This can be accomplished by making a binary trie of numbers in A, then for X going down the opposite path of its binary representation (i.e. trying to maximise the XOR by getting as much variance as possible).


## Trie implementation using 2D Array 
I liked this method but it actually turned out to be harder for me than the struct/pointer based implementation. Anyway, here are the resources to use if you want to implement using 2D Array - 
1. https://leetcode.com/problems/implement-trie-prefix-tree/discuss/931022/trie-implementation-using-2d-array
2. https://codeforces.com/contest/1625/submission/142528661 (Tourist's solution)

## Trie - Implementation (Better)

Represent a Trie using a struct.

```c++
#define M 26

struct Trie {
    Trie* bit[M];
    bool endOfWord = false;
};
Trie* root;
```
Insertion operation in a Trie.
```c++
void insert(string word) {
    Trie* temp = root;
    for(auto ch : word) {
        int b = ch - 'a';
        if(!temp->bit[b]) {
            temp->bit[b] = new Trie();
        }
        temp = temp->bit[b];
    }
    temp->endOfWord = true;
}
```
Search if a string is present in a Trie.
```c++
bool search(string word) {
	Trie* temp = root;
	for(auto ch : word) {
		int b = ch - 'a';
		if(!temp->bit[b]) return false;
		temp = temp->bit[b];
	}
	if(temp->endOfWord) return true;
	return false;
}
```

Problem : Finding maximum XOR of a given number in an array.

```c++
struct Trie {
    Trie* bit[2];
    int data = -1;
};
    
Trie* root;
    
void insert(int n) {
    Trie* temp = root;
    for(int i = 0; i < 31; i++) {
        int b = (n >> (30 - i)) & 1;
        if(!temp->bit[b]) {
            temp->bit[b] = new Trie();
        }
        temp = temp->bit[b];
    }
    temp->data = n;
}
    
int max_xor(int n) {
    Trie* temp = root;
    for(int i = 0; i < 31; i++) {
        int b = (n >> (30 - i)) & 1;
        if(!temp->bit[!b]) {
            temp = temp->bit[b];
        }
        else {
            temp = temp->bit[!b];
        }
    }
    return n^(temp->data);
}
```
Alternate (non trie-based) solution:
1. https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/discuss/91049/Java-O(n)-solution-using-bit-manipulation-and-HashMap
2. https://codeforces.com/contest/706/submission/26743619

Delete operation in Trie : Delete in bottom-up manner. In struct Trie, keep count of times a node has been used and a pointer to parent node. When count of node becomes 0, delete that node. 

```c++
struct Trie {
    Trie* bit[2];
    int cnt = 0;
    int data = -1;
    Trie* parent; 
    int b;
};
Trie* root;

void insert(int n) {
    Trie* temp = root;
    for(int i = 0; i < 31; i++) {
        int b = (n>>(30-i)) & 1;
        if(!temp->bit[b]) {
            temp->bit[b] = new Trie();
            temp->bit[b]->parent = temp;
            temp->bit[b]->b = b;
        }
        temp->cnt++;
        temp = temp->bit[b];
    }
    temp->cnt++;
    temp->data = n;
}

void erase(int n) {
    Trie* temp = root;
    for(int i = 0; i < 31; i++) {
        int b = (n>>(30-i)) & 1;
        temp = temp->bit[b];
    }
    Trie* par = root;
    while(temp!=root) {
        temp->cnt--;
        par = temp->parent;
        if(temp->cnt == 0) {
            par->bit[temp->b] = nullptr; // Not sure if this actually "deletes" the pointer and frees up memory, though.
        }
        temp = par;
    }
    temp->cnt--;
}
```

# Segment Tree

## Resources:
1. https://cp-algorithms.web.app/data_structures/segment_tree.html
2. https://leetcode.com/articles/a-recursive-approach-to-segment-trees-range-sum-queries-lazy-propagation/
3. https://www.hackerearth.com/practice/notes/segment-tree-and-lazy-propagation/

## Template (Basic)
```c++
template <typename T>
class SegTree {
public:
    vector <T> tree;

    SegTree(int size) {
        tree.resize(size);
    }

    T func(T a, T b) {
        return a + b; // Segment tree for the sum
        // return min(a, b); // Segment tree for the minimum
    }

    void build(int node, int start, int end, vector <T> &v) {
        if(start == end) {
            tree[node] = v[start];
        } else {
            int mid = (start + end)/2;
            build(2*node, start, mid, v);
            build(2*node + 1, mid + 1, end, v);
            tree[node] = func(tree[node*2], tree[node*2 + 1]);
        }
    }

    void update(int node, int start, int end, int pos, T val) {
        if(start == end) {
            tree[node] = val; // Assign value here.
        } else {
            int mid = (start + end)/2;
            if(pos <= mid) {
                update(node*2, start, mid, pos, val);
            } else {
                update(node*2 + 1, mid + 1, end, pos, val);
            }
            tree[node] = func(tree[node*2], tree[node*2 + 1]);
        }
    }

    T query(int node, int start, int end, int l, int r) {
        if(l > r) {
            return 0; // Return appropriate value, for example INF for minimum.
        }
        if(l == start && r == end) {
            return tree[node];
        }
        int mid = (start + end)/2;
        return func(query(node*2, start, mid, l, min(mid, r)), query(node*2 + 1, mid + 1, end, max(l, mid + 1), r));
    }
};
```

# Fenwick Tree

This basic implementation of Fenwick Tree (addition on element, sum on interval) is useful because it's much easier to implement than Segment Tree.

```c++
const int N = 200100;
int ft[N];

void update(int i, int n, int x) {
    while(i < n) {
        ft[i] += x;
        i |= i + 1;
    }
}

int query(int i) {
    int x = 0;
    while(i >= 0) {
        x += ft[i];
        i &= i + 1;
        i--;
    }
    return x;
}
```

