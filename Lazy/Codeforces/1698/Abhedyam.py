f = [1]
for i in range(1, 22):
    f.append(f[-1] * i)

for _ in range(int(input())):
    s = input()
    t = [0]*26
    for x in s:
        t[ord(x) - ord('a')] += 1
    ans = 1
    for i in t:
        ans *= f[i]
    print(ans)