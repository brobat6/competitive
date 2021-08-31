def solve(n):
    #Gives the desired answer for an n*n chessboard
    ans = 0
    if n==1:
        ans = 0
    elif n==2:
        ans = 6
    else:
        ans = int(((n**2)*((n**2)-1))/2) - 4*(n-1)*(n-2)
    print(ans)

N = int(input())
for n in range(1,N+1):
    solve(n)