from random import randint as ri

arr = list()

F = open("2.in", "w")
t = 64
F.write(f"{t}\n")
for a in range(1, 9):
    for b in range(1, 9): 
        arr.append([a, b])
        F.write(f"{a} {b}\n")
F.close()

G = open("2.out", "w")
for i in range(t):
    a = arr[i][0]
    b = arr[i][1]
    ans = 0
    for i in range(1, 9):
        for j in range(1, 9):
            if(i == a and j == b):
                continue
            if(i == a or j == b or i - a == j - b or i - a == b - j):
                ans += 1
    G.write(f"{ans}\n")
G.close()