arr = []

def cr(i):
    return(arr[i][0]==arr[i][1]==arr[i][2])

def cc(i):
    return(arr[0][i]==arr[1][i]==arr[2][i])

def crd(i):
    return(arr[i][0]==arr[i][1]==arr[i][2]=='_')

def ccd(i):
    return(arr[0][i]==arr[1][i]==arr[2][i]=='_')

def check():
    num = 0
    for i in range(3):
        num += cr(i)
        num += cc(i)
    for i in range(3):
        num -= crd(i)
        num -= ccd(i)
    num += (arr[0][0]==arr[1][1]==arr[2][2]=='O')
    num += (arr[0][0]==arr[1][1]==arr[2][2]=='X')
    num += (arr[0][2]==arr[1][1]==arr[2][0]=='O')
    num += (arr[0][2]==arr[1][1]==arr[2][0]=='X')
    return num

for _ in range(int(input())):
    t1 = input()
    t2 = input()
    t3 = input()
    arr.append([t1[0],t1[1],t1[2]])
    arr.append([t2[0],t2[1],t2[2]])
    arr.append([t3[0],t3[1],t3[2]])
    num_vic = check()
    print(num_vic)