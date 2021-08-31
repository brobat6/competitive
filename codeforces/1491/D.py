def func():
    a, b = input().split()
    if(int(a)>int(b)):
        print("NO")
        return 0
    bina = str(bin(int(a)).replace("0b",""))
    binb = str(bin(int(b)).replace("0b",""))
    n = len(binb)
    m = len(bina)
    arr1 = []
    arr2 = []
    for i in range(n):
        arr2.append(binb[i])
    for i in range(n):
        if(i<(n-m)):
            arr1.append('0')
        else:
            arr1.append(bina[i-(n-m)])
# print(arr1)
# print(arr2)
    count = 0
    temp = 0
    dummy = 1
    for i in range(n-1,-1,-1):
        if count>(n-m):
            if arr2[i]=='1' and temp == 1:
                print("NO")
                dummy = 0
                break
            elif arr2[i]=='1' and temp == 0:
                temp = 1
        else:
            if arr1[i]=='0' and arr2[i]=='1':
                print("NO")
                dummy = 0
                break
            count += 1
    if dummy==1:
        print("YES")

t = int(input())
for x in range(t):
    func()

