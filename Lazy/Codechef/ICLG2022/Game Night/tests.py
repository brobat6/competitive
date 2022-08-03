from random import randint as ri
import random
M = 1000000
Mt = 100000
Ms = 1000
Ff = list()
for i in range(50):
    Ff.append(ri(100, 100000))
for i in range(13, 15):
    F = open(f"{i}.in", "w")
    arr = list()
    sum = 0
    for j in range(100):
        n = ri(1, Ms)
        m = ri(1, Mt//n)
        if(ri(1, 2) == 1):
            t = n
            n = m
            m = t
        if(sum + (n*m) > M):
            continue
        arr.append([n, m])
        sum += n * m
    # print(arr)
    random.shuffle(arr)
    # print(arr)
    t = len(arr)
    F.write(f"{t}\n")
    for j in range(t):
        n = arr[j][0]
        m = arr[j][1]
        F.write(f"{n} {m}\n")
        def_x = ri(1, n) # One definite red box
        def_y = ri(1, m) 
        for a in range(1, n + 1):
            for b in range(1, m + 1):
                if(a == def_x and b == def_y):
                    F.write("R")
                else:
                    if(ri(1, Ff[i]) == 1):
                        F.write("G")
                    else:
                        F.write("R")
            F.write("\n")
    F.close()