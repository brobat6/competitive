def solve():
    parent = [0]*1010
    for i in range(1010):
        parent[i] = i
    rank = [0]*1010
    def MakeSet(x):
        parent[x] = x
        rank[x] = 1
    def Find(x):
        if parent[x]!=x:
            parent[x] = Find(parent[x])
        return parent[x]
    def Union(x, y):
        xRoot = Find(x)
        yRoot = Find(y)
        if rank[xRoot] > rank[yRoot]:
            parent[yRoot] = xRoot
        elif rank[xRoot] < rank[yRoot]:
            parent[xRoot] = yRoot
        else:
            parent[yRoot] = xRoot
            rank[xRoot] += 1
    def Tarjan(u):
        MakeSet(u)
        ancestor[u] = u
        
    n = int(input())
    for i in range(n-1):
        a, b = map(int, input().split())
        Union(a, b)
    

for _ in range(int(input())):
    solve()