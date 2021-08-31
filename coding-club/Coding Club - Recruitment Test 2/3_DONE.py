k,n = map(int,input().split())
ini = list(map(int,input().split()))

grr = [k - ini[-1]+ini[0]]

for i in range(1,n):
    grr.append(ini[i]-ini[i-1])

grr.sort()
grr.pop()
print(sum(grr))