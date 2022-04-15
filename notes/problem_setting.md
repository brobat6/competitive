# Problem Setting

- [Problem Setting](#problem-setting)
  - [Add AP to sub-segment](#add-ap-to-sub-segment)

## Add AP to sub-segment

Difficulty - 1000
Inspired from - https://codeforces.com/contest/1661/problem/D

You are given an array A of N positive integers. You have to perform various operations on this array. In one operation, you can pick any SUBSEQUENCE of the array and subtract 1 from the first element, 2 from the second element, 3 from the third.....k from the k^th and so on. Your task is to find the minimum number of operations needed to make every element of the array negative.

Constraints - Size of array = 2 * 10^5

Solution - The answer is max(v[0]/1, v[1]/2, v[2]/3, v[3]/4, ....)