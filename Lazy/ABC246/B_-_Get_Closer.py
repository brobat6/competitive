import math

a, b = map(int, input().split())
if(a == 0):
    print(0, 1)
elif(b == 0):
    print(1, 0)
else:
    print(math.sin(math.atan2(a,b)), math.cos(math.atan2(a,b)))