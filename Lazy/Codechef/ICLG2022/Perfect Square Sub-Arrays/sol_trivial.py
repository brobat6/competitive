from math import sqrt

F = open("0_py.out", "w")
G = open("0.in", "r")

for _ in range(int(G.readline())):
    n, q = map(int, G.readline().split())
    arr = [1]*n
    for i in range(q):
        x = list(map(int, G.readline().split()))
        if(x[0] == 1):
            for j in range(x[1] - 1, x[2]):
                arr[j] *= x[3]
        else:
            ans = 1
            for j in range(x[1] - 1, x[2]):
                ans *= arr[j]
            y = round(sqrt(ans))
            F.write("YES\n" if y * y == ans else "NO\n")

F.close()