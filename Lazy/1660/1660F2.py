

for _ in range(int(input())):
    n = int(input())
    s = input()
    pref = list()
    pref.append(0)

    for i in range(n):
        pref.append(pref[-1])
        pref[-1] += (1 if s[i] == '+' else -1)
    ans = 0
    print(pref)
    for i in range(3):
        arr = list()
        for j in range(n + 1):
            if(pref[j] % 3 == i):
                arr.append(pref[j])
        print(arr)
    print(ans)