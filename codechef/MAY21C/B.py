for _ in range(int(input())):
    n, x, k = map(int, input().split())
    print("YES" if (x%k==0 or (n+1-x)%k==0) else "NO")