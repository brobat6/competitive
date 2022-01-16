- [Trie](#trie)
  - [Resources:](#resources)
  - [Problems:](#problems)
  - [Trie implementation using 2D Array](#trie-implementation-using-2d-array)
  - [Trie - Implementation (Better)](#trie---implementation-better)

# Trie

## Resources:

1. https://leetcode.com/problems/implement-trie-prefix-tree/solution/
2. https://codeforces.com/blog/entry/15729
3. https://leetcode.com/problems/implement-trie-prefix-tree/discuss/931022/trie-implementation-using-2d-array

## Problems:

1. https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3ff3#problem. Solution - https://codingcompetitions.withgoogle.com/kickstart/submissions/000000000019ffc7/00000000005a8fe0
2.  https://codeforces.com/contest/1625/problem/D. Solution - https://codeforces.com/contest/1625/submission/142528661
3.  https://codeforces.com/problemset/problem/706/D
4.  https://www.codechef.com/JAN15/problems/XRQRS
5.  https://codeforces.com/contest/456/problem/D

Trie is quite useful in XOR related queries. Say we are given a number X (per query) and an array of numbers A and we want to find A[i] such that x^A[i] is maximum. This can be accomplished by making a binary trie of numbers in A, then for X going down the opposite path of its binary representation (i.e. trying to maximise the XOR by getting as much variance as possible).


## Trie implementation using 2D Array 
I like this because it avoids pointers, classes and all of that stuff.
Lets create a trie to store binary representation of numbers.

```c++
vector<vector<int>> trie(1, vector<int>(2, -1));
// The dimensions of trie are [Number_of_nodes][Size_of_alphabet]. In this case, we are going for binary representation so the size of alphabet is 2. Whenever we are adding a new link, i.e. a new node, we will increase the size of the trie. The node 0 is the root of the trie.
vector <int> idx(1, -1);
// This stores the value of the data in a node. We can have various representations of this. For example, in case all we care about is finding whether a string is in the trie or not, we can use "unordered_set<int> en;" Where en will have all the values that correspond to end nodes. Basically, this is where we will actually "store" our answer, the data here will be modified according to whatever the question asks.
int nx = 0; 

void insert(int x) {
// Insert the number x into the trie.
    // First, find the bitwise representation of x. Lets say it is stored in the following vector.
    vector <int> bits;
    int t = 0; // Currently points to the root.
    for(int i = 0; i < bits.size(); i++) {
        int t = 0;
        int bit = bits[i];
        // Now for the main part of insertion.
        if(trie[t][bit] == -1) {
            trie[t][bit] = trie.size(); // trie[t][bit] is given a new node. 
            trie.push_back({-1, -1});
            idx.push_back(-1);
        }
        t = trie[t][bit]; 
        // Now t points to the next node.
    }
    idx[t] = nx; // Give the unique ID to this number. In case of unordered set, go for en.insert(t);
    nx++;
}

bool find(int x) {
// Find if x exists in the trie.
    vector <int> bits;
    int t = 0;
    for(int i = 0; i < bits.size(); i++) {
        int bit = bits[i];
        if(trie[t][bit] == -1) return false;
        t = trie[t][bit];
    }
    // The number x is present in idx[t].
    return true;
}
```

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

