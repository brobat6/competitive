a = list()
b = list()
N = 40208
for i in range(N):
    a.append(input())
for i in range(N):
    b.append(input())
p = 0
for i in range(N):
    if(a[i] != b[i]):
        p += 1
print(p)   