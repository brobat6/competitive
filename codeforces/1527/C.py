arr = [1, 1, 2, 2]
n = len(arr)
ans = 0
for i in range(n-1):
    for j in range(i+1, n):
        grr = arr[i:(j+1)]
        d = dict()
        for x in grr:
            try:
                d[x] += 1
            except:
                d[x] = 1
        for x in d:
            if d[x]>1:
                ans += (d[x]*(d[x]-1))/2
print(int(ans))