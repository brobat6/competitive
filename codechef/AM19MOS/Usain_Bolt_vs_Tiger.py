import math
for _ in range(int(input())):
    f, d, a, v = map(int, input().split())
    if(math.sqrt(2*(d+f)/a) > (f/v)):
        print("Bolt")
    else:
        print("Tiger")