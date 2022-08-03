for _ in range(int(input())):
    a, b, c, d = map(int, input().split())
    x = min(abs(d - b), abs(c - a))
    y = max(abs(d - b), abs(c - a))
    y -= x
    ans = x * 2
    if(y % 2):
        ans += 1
        y -= 1
    ans += y * 2
    print(ans)