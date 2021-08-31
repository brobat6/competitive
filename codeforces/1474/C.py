def func():
    n = int(input())
    arr = list(map(int,input().split()))
    arr.sort()
    for i in range(len(arr)-1):
        if(not arr):
            break
        x = arr[-1] + arr[i]
        temp = 'YES'
        grr = arr
        crr = []
        j = i
        while(grr):
            val = 0
            crr.append(grr.pop(j))
            crr.append(grr.pop(-1))
            for k in range(len(grr)-1):
                if x-grr[-1]==grr[k]:
                    x = grr[-1]
                    j = k
                    val = 1
                    break
                if val!=1:
                    temp = 'NO'
                    break
        if temp=='NO':
            continue
        elif temp=='YES':
            print(crr)
            break
    
                    
t = int(input())

for _ in range(t):
    func()