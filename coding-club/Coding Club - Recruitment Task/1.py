def func(query,low,high):
    mid = (low+high)//2
    if query <= arr[mid] and query > arr[mid-1]:
        return mid
    elif query > arr[mid] and query <= arr[mid+1]:
        return mid+1
    elif query < arr[mid]:
        return func(query,low,mid)
    elif query > arr[mid]:
        return func(query,mid,high)

n,m = map(int,input().split())
arr = [0]
for _ in range(n):
    c,t = map(int,input().split())
    x = arr[-1] + (c*t)
    arr.append(x)
#print(arr)

query_store = list(map(int, input().split()))
ans_store = [1]
for query in query_store:
    ans_store.append(func(query,ans_store[-1],n))
for i in range(1,m+1):
    print(ans_store[i],end=' ')