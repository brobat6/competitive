# for _ in range(int(input())):
#     n = int(input())
#     arr = list(map(int, input().split()))
#     arr.sort()
#     # [-4, -3, -2, 0, 1, 4, 6]
#     grr = []
#     for i in range(1, n):
#         grr.append(arr[i]-arr[i-1])
#     # [1, 1, 2, 1, 3, 2]
#     for i in range(1, n-1):
#         grr[i] = min(grr[i], grr[i-1])
#     # [1, 1, 1, 1, 1, 1]
#     for i in range(n-1):
#         if(grr[i]<arr[i+1]):
#             print(i+1)
#             break
#         if(i==(n-2)):
#             print(n)

for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()
    x = arr.count(0)
    for i in range(n):
        if(arr[i]>0):
            if(x>1):
                print(i)
            else:
                print(i+1)
            break
        if(i==(n-1)):
            print(n)