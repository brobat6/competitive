def func():
    n = int(input())
    grr = input()
    N = 0
    for i in range(len(grr)):
        if(grr[i]=='*') N+=1
    r = [0]*N
    for i in range(len(grr)):
        if(grr[i]=='*'):
            if N==0:
                pass
            else:
                

for _ in range(int(input())):
    print(func())