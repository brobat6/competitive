def func(arr,N,sum):
    mydict = dict()
    for i in range(N):
        if arr[i]<sum:
            ans = "IMPOSSIBLE"
            temp = sum - arr[i]
            if temp in mydict:
                ans = "POSSIBLE"
                value1 = temp
                value2 = arr[i]
                break
            if arr[i] in mydict:
                mydict[arr[i]] += 1
            else:
                mydict[arr[i]] = 1
    print(ans)
    if ans=="POSSIBLE":
        print(value1,value2)

N,X = map(int, input().split())
arr = list(map(int, input().split()))
func(arr,N,X)