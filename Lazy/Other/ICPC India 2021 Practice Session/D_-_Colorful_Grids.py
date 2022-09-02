MOD = 1_000_000_007

def pow(a, b):
    res = 1
    while(b):
        if(b & 1):
            res = res * a % MOD
        a = a * a % MOD
        b >>= 1
    return res

INV_4 = pow(4, MOD - 2)

for _ in range(int(input())):
    n, c = map(int, input().split())
    n = 5*n*n
    flag = False
    if(n % 2):
        n -= 1
        flag = True
    ans = 0
    ans += pow(c, n)
    ans += 2*pow(c, n//4)
    ans += pow(c, n//2)
    ans *= INV_4
    if(flag):
        ans *= c
    print(ans % MOD)