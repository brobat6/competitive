# Problem Setting

- [Problem Setting](#problem-setting)
  - [Add AP to sub-segment](#add-ap-to-sub-segment)
  - [Alternative Segment Tree](#alternative-segment-tree)

## Add AP to sub-segment

Difficulty - 1000
Inspired from - https://codeforces.com/contest/1661/problem/D

You are given an array A of N positive integers. You have to perform various operations on this array. In one operation, you can pick any SUBSEQUENCE of the array and subtract 1 from the first element, 2 from the second element, 3 from the third.....k from the k^th and so on. Your task is to find the minimum number of operations needed to make every element of the array negative.

Constraints - Size of array = 2 * 10^5

Solution - The answer is max(v[0]/1, v[1]/2, v[2]/3, v[3]/4, ....)

## Alternative Segment Tree

Difficulty - 1400
Inspired from - Last line of https://codeforces.com/blog/entry/102013?#comment-904992

Note - Not good for contest, good for interview. Interesting approach


Question - An array, initially empty. Q updates --> Insert (x_i, y_i) into the array.
--> For a given X, find the maximum Y over all pairs that have x_i >= X. 10^5 queries.

Obviously there exists an easy way to do using segment tree.
If (x_i, y_i) had a huge range, then segment tree could be implemented by first processing all insertions and hashing values to smaller ones. But the approach below is easier:

Solution - 
Make a map such that m[x] = y.

For calling a query on X, we want to just ask for lower_bound of x on the map. How to achieve this?

--> All values with smaller X and smaller Y are useless. 

At every insert, go through all lower values and whenever there is a smaller Y, delete from the map. Else, break.

This means that at any point of the array, as X will keep increasing, so will Y. At most O(n) deletions in total [proof idk]