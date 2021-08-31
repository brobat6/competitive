from decimal import *
getcontext().prec = 6

def func():
    grr = arr
    count = len(grr)
    if grr[0][0]!=0:
        return -1
    start = 0
    end = grr[0][1]
    for i in range(1,len(grr)):
        if grr[i][0]>end:
            return -1
        if grr[i][0]>start and grr[i][1]<end:
            count -= 1
            continue
        try:
            if grr[i+1][0]<end and grr[i][0]<end:
                if grr[i][1] < grr[i+1][1]:
                    count -= 1
                    continue
        except:
            pass
        if grr[i][0]<end and grr[i][1]>end:
            end = grr[i][1]
    if end!=l:
        return -1
    return count


while True:
    try:
        n,l,w = map(int,input().split())
        arr = []

        for _ in range(n):
            a,b = map(float,input().split())
            d = (b**2) - ((w**2)/4)
            if d>0:
                c = float(Decimal(d).sqrt())
                arr.append([a-c,a+c])
                if arr[-1][0]<0:
                    arr[-1][0] = 0
                if arr[-1][1]>l:
                    arr[-1][1] = l
    
        arr.sort()
        print(func())
    except:
        break