print(1)
print(2000)
from random import randint as ri
for i in range(2000):
    if(ri(1, 2) == 1):
        print('+', end ='')
    else:
        print('-', end = '')