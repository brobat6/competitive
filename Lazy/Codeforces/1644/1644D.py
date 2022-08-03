for _ in range(int(input())):
    n, m, k, q = map(int, input().split())
    query = list()
    for i in range(q):
        query.append(list(map(int, input().split())))
    r = [0]*(n + 1)
    c = [0]*(m + 1)
    cnt_r = 0
    cnt_c = 0
    cnt = 0
    for i in range(q - 1, -1, -1):
        yes = False
        if(r[query[i][0]] == 0):
            r[query[i][0]] = 1
            yes = True
            cnt_r += 1
        if(c[query[i][1]] == 0):
            c[query[i][1]] = 1
            yes = True
            cnt_c += 1
        if(yes):
            cnt += 1
        if(cnt_r == n or cnt_c == m):
            break
    MOD = 998244353
    ans = 1
    for i in range(cnt):
        ans = (ans * k) % MOD
    print(ans)