def func(s, m):
    # find answer assuming the period is m.
    # print(s, m)
    t = str()
    for i in range(len(s)//m):
        for j in range(m):
            t += s[j]
    # print(t)
    if(int(t) <= int(s)):
        return int(t)
    else:
        u = str()
        for j in range(m):
            u += s[j]
        u = str(int(u) - 1)
        # print(u)
        if(len(u) < m):
            u = '0' + u
        # print(u)
        for i in range(len(s)//m - 1):
            for j in range(m):
                u += u[j]
        # print(u)
        return int(u)
    

for _ in range(int(input())):
    s = input()
    l = len(s)
    ans = str()
    for i in range(l - 1):
        ans += '9'
    ans = int(ans)
    for i in range(1, l):
        if(l % i == 0):
            ans = max(ans, func(s, i))
    print(ans)
