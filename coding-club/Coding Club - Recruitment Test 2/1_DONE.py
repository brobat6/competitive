x,y = map(int,input().split())
arr = []
for _ in range(y):
    arr.append(list(input().split()))
for i in range(y):
    arr[i][0] = int(arr[i][0])
    if arr[i][1]=='WA':
        arr[i][1] = -1
    else:
        arr[i][1] = 1

grr = [0]*x

for i in range(y):
    ques = arr[i][0]
    if grr[ques-1] > 0:
        pass
    else:
        if arr[i][1] == -1:
            grr[ques-1] -= 1
        else:
            if grr[ques-1]==0:
                grr[ques-1] = 0.03
            else:
                grr[ques-1] *= -1

ca = 0
pen = 0
for i in range(x):
    if grr[i]==0.03:
        ca += 1
    else:
        if grr[i]>0:
            ca += 1
            pen += grr[i]

print(ca,pen)