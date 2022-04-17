from random import randint as ri
for i in range(3):
    F = open(f"nCr/input/input0{i}.txt", "w")
    t = 100
    F.write(f"{t}")
    for i in range(t):
        a = ri(0, 30)
        b = ri(0, a)
        F.write(f"\n{a} {b}")
    F.close()