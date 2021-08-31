def func():
    ans,v1,v2 = 0,0,0
    for i in range(N):
        if arr[i]<X:
            temp = X - arr[i]
            if val[temp]==0:
                val[arr[i]]=1
            else:
                ans = 1
                v1 = arr[i]
                v2 = temp
                break
    if ans==0:
        print("IMPOSSIBLE")
    if ans==1:
        print("POSSIBLE")
        print(v1,v2)

N,X = map(int,input().split())
arr = list(map(int,input().split()))
val = []
for i in range(max(arr)+X+1):
    val.append(0)
func()