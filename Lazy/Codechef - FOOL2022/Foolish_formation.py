for _ in range(int(input())):
    n = int(input())
    arr = list(input().split())
    s = ""
    for i in arr:
        s += i[0]
    print("YES" if s in arr else "NO")