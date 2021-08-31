def func(sum):
    num_sam,num_morty,num_rick = 1,1,1
    mydict = []
    for i in range(sum+1):
        mydict.append(0)
    while (sum > ((num_sam)*(num_sam+1))//2):
        mydict[((num_sam)*(num_sam+1))//2] = 1
        num_sam += 1
    dummyVal = num_sam
    num_sam = -1
    for i in range(1,dummyVal+1):
        for j in range(1,dummyVal+1):
            sum_1 = (i*(i+1))//2
            sum_2 = (j*(j+1))//2
            dummySum = sum_1 + sum_2
            temp = sum - dummySum
            if temp > 0:
                if mydict[temp]!=0:
                    num_sam = int((-1+(1+(8*temp))**0.5)//2)
                    num_morty = i
                    num_rick = j
                    break
    if num_sam==-1:
        print("IMPOSSIBLE")
    else:
        print(num_sam,num_morty,num_rick)

sum = 100000
func(sum)
