for _ in range(int(input())):
    n = int(input())
    s = input()
    if(s.find('a') != -1 or s.find('b') != -1 or s.find('c') != -1):
        print("not bat")
    else:
        print("bat")