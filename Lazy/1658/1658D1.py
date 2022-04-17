arr = [0, 1, 2, 3, 4, 5, 6, 7]
# arr = [0, 1, 2]
arr = [3, 4, 5]
for i in range(20):
    print(i, end = '=')
    for j in arr:
        print(j ^ i, end = ' ')
    print()