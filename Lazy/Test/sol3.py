n = int(input())
arr = list(map(int, input().split()))
ans = arr[0] + arr[1]
for i in range(2, n):
    ans = max(ans, arr[i] + arr[i - 1])
print(ans)