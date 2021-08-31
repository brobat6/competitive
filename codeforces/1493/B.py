def func():
    h, m = map(int, input().split())
    s = input()
    h1 = int(s[0])
    h2 = int(s[1])
    m1 = int(s[3])
    m2 = int(s[4])
    opps = [0,1,5,-1,-1,2,-1,-1,8,-1]
    if(opps[h1]==-1): 
        return "00:00"
    if(opps[h2]==-1): 
        return "00:00"
    if(opps[m1]==-1): 
        return "00:00"
    if(opps[m2]==-1): 
        return "00:00"
    # By now we know opposite exists.
    if(((10*opps[m2])+opps[m1])>=h):
        return "00:00"

for _ in range(int(input())):
    print(func())