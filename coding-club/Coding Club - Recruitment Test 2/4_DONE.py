def func(arr):
    if len(arr) == len(set(arr)):
        return False
    else:
        return True

n = int(input())
arr = list(map(int,input().split()))
ans = func(arr)
if ans:
    print('NO')
else:
    print('YES')  