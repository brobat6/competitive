# https://www.spoj.com/problems/VECTAR8/


n = 100
arr = [0]*(n+1)
primes = []
for i in range(2,n+1):
    if(arr[i]==0):
        arr[i] = 1
        primes.append(i)
        for j in range(i,n+1,i):
            arr[j] = 1

def isPrime(z):
    n = z
    count = 0
    while n!= 0:
        n //= 10
        count += 1
    if(count==1):
        return True
    t = z % (10**(count-1))
    try:
        if(oP[t]==1):
            return True
    except:
        return False
    return False

oP = dict()
for p in primes:
    if(isPrime(p)):
        oP[p] = 1

s = []

for o in oP:
    s.append(o)

s.sort()

import bisect

T = int(input())
for _ in range(T):
    N = int(input())
    print(bisect.bisect_right(s,N,lo=0,hi=len(s)))
