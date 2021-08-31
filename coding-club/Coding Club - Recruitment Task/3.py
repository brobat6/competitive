def func():
    n,k = map(int,input().split())
    string = input()
    arr = []
    for i in range(n):
        arr.append(int(string[i]))
    grr = []
    corner = []
    index,iti = 0,0
    while(index<n):
        if arr[index]==1 and iti!=0:
            grr.append(iti)
            iti = 0
        elif arr[index]==0:
            iti += 1
        if index==(n-1):
            grr.append(iti)
        index += 1
    if arr[0]==0:
        corner.append(grr.pop(0))
    if arr[n-1]==1:
        grr.pop()
    else:
        corner.append(grr.pop())
    num = 2*len(grr)+len(corner)
    if num<=k:
        print(0)
    else:
        grr.sort(reverse=True)
        corner.sort(reverse=True)
        zeroes = sum(grr)+sum(corner)
        a1,a2,a3 = 0,0,0
        a1 = sum(grr[:(k//2)])
        if len(corner)>0:
            a2 = corner[0] + sum(grr[:((k-1)//2)])
        if len(corner)>1 and k>1:
            a3 = sum(corner) + sum(grr[:((k-2)//2)])
        a = max(a1,a2,a3)
        print(zeroes-a)
    
T = int(input())
for _ in range(T):
    func()
