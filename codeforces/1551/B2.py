for _ in range(int(input())):
    n, k = map(int, input().split())
    arr = list()
    t = list(map(int, input().split()))
    for i in range(n):
        arr.append([t[i], i, 0])
    arr.sort()
    current_number = 2
    painted = 1
    total_painted = n
    arr[0][2] = 1
    for i in range(1, n):
        # if(current_painted == k):
            # if(arr[i]!=arr[i-1]):
        if(painted == k and arr[i][0]==arr[i-1][0]):
            total_painted -= 1
            continue
        if(arr[i][0]==arr[i-1][0]):
            arr[i][2] = current_number
            current_number = (current_number + 1) % k
            if(current_number==0):
                current_number = 1
            painted += 1
        else:
            arr[i][2] = current_number
            current_number = (current_number + 1) % k
            if(current_number==0):
                current_number = 1
            painted = 1
    total_painted = (total_painted//k)*k
    grr = list()
    for i in range(n):
        grr.append([arr[i][1], arr[i][0], arr[i][2]])
    grr.sort()
    done = 0
    z = False
    for i in range(n):
        if(z):
            print(0, end = ' ')
        else:
            print(grr[i][2], end = ' ')
        if(grr[i][2]!=0):
            done += 1
        if(done==total_painted):
            z = True
    