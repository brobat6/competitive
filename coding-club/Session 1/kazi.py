# https://www.codechef.com/problems/SPIT1

n = int(input())
dic = dict()

maxVal = 0
maxName = ''

for _ in range(n):
    s,v = input().split()
    v = int(v)
    try:
        dic[s] += v
    except:
        dic[s] = v
    if dic[s] > maxVal:
        maxVal = dic[s]
        maxName = s

print(maxName)