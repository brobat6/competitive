def func(arr,num,temp,total_time,index):
    while (index<n):
        if arr[index]=='(':
            num += 1
        else:
            num -= 1
        if num==0 and temp==0:
            index += 1
        elif num>0:
            index += 1
            continue
        elif num<0:
            index += 1
            temp += 1
            continue
        elif num==0 and temp>0:
            total_time += (temp+1)
            index += 1
            num = 0
            temp = 0
    if num==0:
        return total_time
    else:
        return -1

n = int(input())
string = input()
arr = []
for i in range(n):
    arr.append(string[i])
num,temp,index,total_time = 0,0,0,0

if n%2==0:
    print(func(arr,num,temp,total_time,index))
else:
    print(-1)
