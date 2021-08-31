for _ in range(int(input())):
    x, a, b = map(int, input().split())
    print(10*(((100-x)*b)+a))