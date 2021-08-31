def func(i,num,itr):
    if i==1:
        num += itr
    else:
        i = i//2
        num += itr
        itr *= 2
        num = func(i,num,itr)
    return num


num = 0
itr = 1
i = int(input())
num = func(i,num,itr)

print(num)