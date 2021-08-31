def find_min_vertical(x, i, j):
    a = [x[i-1][j], x[i+2][j], x[i][j-1], x[i][j+1], x[i+1][j-1], x[i+1][j+1]]
    for i in range(1, 10):
        try:
            a.index(i)
        except:
            return i

def find_min_horizontal(x, i, j):
    # a = [x[i-1][j], x[i+2][j], x[i][j-1], x[i][j+1], x[i+1][j-1], x[i+1][j+1]]
    a = [x[i][j-1], x[i][j+2], x[i-1][j], x[i+1][j], x[i-1][j+1], x[i+1][j+1]]
    for i in range(1, 10):
        try:
            zzzzz = a.index(i)
        except:
            return i

for _ in range(int(input())):
    n,m,k = map(int, input().split())
    x = [[0]*(m+1)]*(n+1)
    if(n%2==0):
        if(k%2==0 and k<=(n*(m//2))):
            print("YES")
            for i in range(n//2):
                for j in range(m//2):
                    x[i][j] = find_min_horizontal(x, i, j)
                    x[i][j+1] = x[i][j]
                    x[i+1][j] = find_min_horizontal(x, i+1, j)
                    x[i+1][j+1] = x[i+1][j]
            for i in range(n):
                for j in range(m):
                    if(x[i][j]==0):
                        x[i][j] = find_min_vertical(x, i, j)
                        x[i+1][j] = x[i][j]
            for i in range(n):
                for j in range(m):
                    print(chr(x[i][j]+96), end='')
                print()
        else:
            print("NO")
    else:
        x = k - (m//2)
        if(x>=0 and k<=(n*m//2) and x%2==0):
            print("YES")
            # 
        else:
            print("NO")