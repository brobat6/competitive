from random import randint as ri

T = 10000
N = 10
Q = 10
X = 10

for i in range(1):
    F = open(f"{i}.in", "w")
    F.write(f"{T}\n")
    for j in range(T):
        F.write(f"{N} {Q}\n")
        for k in range(Q):
            if(ri(1, 3) == 1 or k == Q - 1):
                a = ri(1, N)
                b = ri(a, N)
                F.write(f"2 {a} {b}\n")
            else:
                x = ri(1, X)
                a = ri(1, N)
                b = ri(a, N)
                F.write(f"1 {a} {b} {x}\n")
    F.close()