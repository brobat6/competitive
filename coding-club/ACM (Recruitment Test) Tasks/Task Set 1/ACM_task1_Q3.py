n = int(input())
arr = []
for _ in range(n):
    arr.append(int(input()))
arr.insert(0,100001)
arr.append(100001)

candies = []
for _ in range(n+2):
    candies.append(0)

for i in range(1,n+1):
    if arr[i-1] >= arr[i] <= arr[i+1]:
        candies[i] = 1

for i in range(1,n+1):
    if arr[i-1] < arr[i] <= arr[i+1]:
        candies[i] = candies[i-1] + 1

for i in range(n,0,-1):
    if arr[i-1] >= arr[i] > arr[i+1]:
        candies[i] = candies[i+1] + 1

for i in range(1,n+1):
    if arr[i-1] < arr[i] > arr[i+1]:
        candies[i] = max(candies[i-1], candies[i+1]) + 1

print(sum(candies))