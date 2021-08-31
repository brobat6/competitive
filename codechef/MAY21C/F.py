def solve(N, M):
    ans = 0
    if(N>M):
        ans += (N*(N-1))//2
        ans -= (M*(M-1))//2
    d = dict() #d[i] = {b : M%b==i}
    size_d = [0]*M #Size of d[i]
    for i in range(M):
        d[i] = list()
    # a - [1, M-1] b - [2, M]
    for b in range(2, min(N+1, M+1)):
        d[M%b].append(b)
        size_d[M%b] += 1
    A = [0]*(M-1) #A[i] = {Number of solns for each a}
    def search(i, a):
        left = 0
        right = size_d[i + (M%a)] - 1
        pos = -1
        while(left <= right):
            mid = (left+right)//2
            if (d[i + (M%a)][mid] <= a):
                left = mid+1
                pos = mid
            else:
                right = mid-1
        return (pos+1)
    for a in range(1, min(M, N)):
        i = 0
        while (i < M):
            try:
                A[a] += size_d[i + (M%a)] - search(i, a)
                i += a
            except:
                break
    print(sum(A)+ans)

for _ in range(int(input())):
    N, M = map(int, input().split())
    solve(N, M)
