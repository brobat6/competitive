for _ in range(int(input())):
    n, l, r = map(int, input().split())
    arr = list(map(int, input().split()))
    arr.sort()
    ans = 0
    if(n==1):
        print(0)
    if(n==2):
        if(arr[0]+arr[1]>=l and arr[0]+arr[1]<=r):
            print(1)
        else:
            print(0)
    else:
        left = [-1]*n
        right = [-1]*n
        