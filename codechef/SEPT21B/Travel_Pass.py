for _ in range(int(input())):
    n, a, b = map(int, input().split())
    x = input().count('1')
    print(b*x + a*(n-x))