- [Stack](#stack)
  - [Problem Statement](#problem-statement)
  - [Sample Input](#sample-input)
  - [Sample Output](#sample-output)
  - [Explanation](#explanation)
  - [Sample Input 2](#sample-input-2)
  - [Sample Output 2](#sample-output-2)
- [Good Sub-Matrices](#good-sub-matrices)
  - [Input](#input)
  - [Output](#output)
  - [Sample input](#sample-input-1)
  - [Sample output](#sample-output-1)
  - [Explanation](#explanation-1)
  - [Elevate and Depress](#elevate-and-depress)
  - [Sample Input 1](#sample-input-1)
  - [Sample Output 1](#sample-output-1)

# Stack 

A **stack** is a special kind of data structure which supports "Last In, First Out" operations. Think of it like a pile of bricks. You can keep placing bricks on top of this pile (i.e. pushing elements to the stack). But if you want to remove bricks, at any given time, you can only remove the top-most brick from the pile (i.e. popping elements from the top of the stack). So, in the stack, the FIRST element that is removed is the LAST element that was inserted. 

For example, if you have an empty stack, and you PUSH 3, then PUSH 4, then PUSH 9, then POP, the element popped will be 9. In the next POP operation, the element popped will be 4. 

## Problem Statement

You are given an array of integers, and a single Stack. You start processing the elements of this array from start to end. When you process each element, you can do one of the following operations : 
1. Do nothing, let the number stay in its position
2. PUSH the number into the stack.
At any instant, you can also
3. POP the top element of the stack, if it is not empty, and pass it into the final array.

Your task is to find the **lexicographically smallest** permutation you can make by doing just these operations.

## Sample Input
Input Array --> 5, 1, 2, 4, 3

## Sample Output
Output Array --> 1, 2, 3, 4, 5

## Explanation
Here is how to achieve this output : 
1. First, we push 5 into the stack.
2. Next, we let 1 pass through unchanged. (The final array is now [1])
3. We let 2 pass through unchanged. (The final array is now [1, 2])
4. We push 4 into the stack. (The top element of the stack is now 4, followed by 5).
5. We let 3 pass. (The final array is now [1, 2, 3]).
6. We POP the top element of the stack and let it pass into the final array (The final array is now [1, 2, 3, 4]).
7. We POP the top element again. The final array now becomes [1, 2, 3, 4, 5].

## Sample Input 2
Input Array --> 8, 6, 6, 10, 3, 2, 3, 5, 9, 8

## Sample Output 2
Output Array --> 2, 3, 3, 5, 8, 9, 10, 6, 6, 8 


# Good Sub-Matrices
You are given an $x \times y$ matrix of integers. This matrix has some special properties:
- The integers in each row from left to right are in non-decreasing order
- The integers in each row from top to bottom are in non-decreasing order

A good sub-matrix is a sub-matrix of the original $x\times y$ matrix, for which the average of all integers in the sub-matrix is $\geq t$.

Find the number of such good sum-matrices of the original matrix.

## Input
The first line of input consists of three integers $x, y, $ and $t$.
The next $x$ lines contain $y$ integers, the original matrix.

## Output
Print the number of good sub-matrices.

## Sample input
>3 3 4
2 2 3
3 4 5
4 5 5

## Sample output
>7

## Explanation
The good sub-matrices are 
>3 4
4 5

>4 5
5 5

>4 (occurs twice)

>5 (occurs thrice)

## Elevate and Depress

There are N pillars, lying on a straight line. The pillars are numbered from 1 to N. You have to perform Q operations on these pillars. Each operation can be of two types:

1. > Elevate L R X

This operation will increase the height of all pillars numbered from L to R (inclusive) by X. 

2. > Depress L R X

This operation will decrease the height of all pillars numbered from L to R (inclusive) by X.

The height of all the pillars is initially 0. 

Your task is to process these Q operations, and then output the final configuration of the pillars. 

## Sample Input 1
Number of pillars = 10

Number of queries = 5

1. Elevate 1 5 1
2. Elevate 4 9 1
3. Depress 3 10 2
4. Depress 1 6 1
5. Elevate 1 5 3

## Sample Output 1
[3, 3, 1, 2, 2, -2, -1, -1, -1, -2]

