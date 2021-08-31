arr = [0, 1]

for i in range(100000):
    arr.append(arr[-1]*2)
    arr[-1] %= 1000000007

for _ in range(int(input())):
    n = int(input())
    print(arr[n])