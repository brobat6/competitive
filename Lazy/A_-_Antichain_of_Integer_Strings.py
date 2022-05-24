for _ in range(int(input())):
    l, r = map(int, input().split())
    if(r < 10):
        print(r - l + 1)
        continue
    x = list()
    s = str(r)
    for i in range(len(s)):
        t = str()
        for j in range(len(s)):
            if(j != i):
                t += s[j]
        x.append(int(t))
    y = max(x)
    y += 1
    print(r - max(y, l) + 1)
        