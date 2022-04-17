n = int(input())
arr = list(map(int, input().split()))
a = sum(arr)
b = 0
for i in arr:
    b += i * i
print(n * b - a * a)