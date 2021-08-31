import math

def func():
    n = int(input())
    if n%2==0:
        return("Gautam")
    

T = int(input())
arr = []
for _ in range(T):
    arr.append(func())
for i in range(T):
    print(arr[i])
