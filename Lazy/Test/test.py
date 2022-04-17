from random import randint as ri

for i in range(61, 62):
    F = open(f"{i}.txt", "w")
    X = 1000000
    Y = 1000000
    n = ri(X - 10, X)
    F.write(f"{n}\n")
    for i in range(n):
        Z = ri(1, 10)
        if(Z != 1):
            F.write(f"0 ")
        else:
            F.write(f"{ri(1, Y)} ")
    F.close()