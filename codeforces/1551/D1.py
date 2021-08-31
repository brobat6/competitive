for _ in range(int(input())):
    n,m,k = map(int, input().split())
    x = [['0']*m]*n
    if(n%2==0):
        if(k%2==0 and k<=(n*(m//2))):
            print("YES")
            # 
        else:
            print("NO")
    else:
        x = k - (m//2)
        if(x>=0 and k<=(n*m//2) and x%2==0):
            print("YES")
            # 
        else:
            print("NO")