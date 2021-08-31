n = int(input())
arr = dict()
for _ in range(n):
    temp = input()
    try:
        arr[temp] += 1
    except:
        arr[temp] = 1

x = max(arr.values())
grr = []

for i in arr:
    if arr[i]==x:
        grr.append(i)

grr.sort()

for i in grr:
    print(i)