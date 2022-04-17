from random import randint as ri
for i in range(10):
    F = open(f"input/input0{i}.txt", "w")
    n = ri(1, 100)
    m = ri(1, 100)
    F.write(f"{n} {m}")
    for i in range(n):
        F.write("\n")
        for j in range(m):
            F.write(f"{ri(0, 100)}")
            if(j != m - 1):
                F.write(f" ")
    F.close()