I solved E by keeping track of all the intervals formed after connecting $k$ edges, using DSU. 

In DSU, similar to parent/size, we store the ranges covered by each set in the form of a set of $[l, r]$ pairs. Anytime two intervals are merged, our goal is to recalculate the $[l, r]$ ranges in the larger set, after having added the elements of the smaller set to it. Whenever a new range is formed, we note the time when it was formed. This will give us all the possible ranges of the form $[l, r, k]$, which means that it is possible to connect all vertices within $[l, r]$ using the first $k$ edges.

<spoiler summary="Example">
Suppose that initially the larger set contains ranges: $[1, 3], [6, 7], [10, 11]$ and the smaller set contains ranges: $[4, 4], [8, 9]$. First, we merge $[4, 4]$. Query using lower_bound on the larger set and get the previous and next ranges. In this case, it is possible to merge $[4, 4]$ with $[1, 3]$, giving a new range $[1, 4]$.

Next, up, we see that it is possible to merge $[8, 9]$ with both $[6, 7]$ and $[10, 11]$. We do that and get a new range $[6, 11$
</spoiler>

<spoiler summary="Why can we merge intervals without TLE?">
The key is to do union by size. We will only merge smaller size sets into the larger size sets. Think about how many times a particular range will have to change sets, i.e., be merged. Since we'll only merge with larger sets, the size of a set will atleast double after every merging. So, every element/range will go through $O(Log N)$ merges.
</spoiler>

See my DSU class for more clarity : [submission:164821167]

Now the problem reduces to this: We have a bunch of ranges of the form $[l, r, k]$, and queries of the form $[x, y]$. For each query, we have to find the range with minimal $k$ such that $l <= x$ and $r >= y$. This can be solved by using a segment tree for the minimum. Sort the ranges and queries by their left ends. Try to minimize $k$ for each right end of a range. For a query, find the minimum $k$ for all $r$ such that $y <= r <= n$.  

Time complexity : $O(N Log^{2}N)$ for merging sets using DSU. 