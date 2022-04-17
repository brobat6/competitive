for _ in range(int(input())):
    a, s = map(int, input().split())
    if(s - 2 * a >= 0 and ((s - 2 * a)&a == 0)):
        print("Yes")
    else:
        print("No")