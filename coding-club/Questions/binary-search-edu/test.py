from random import randint as ri
for i in range(20, 40):
    F = open(f"{i}.txt", "w")
    n = ri(99990, 100000)
    k = ri(1, n**2)
    F.write(f"{n} {k}\n")
    for j in range(n):
        F.write(f"{ri(1, 10000)} ")
    F.write("\n")
    for j in range(n):
        F.write(f"{ri(1, 10000)} ")
    F.close()