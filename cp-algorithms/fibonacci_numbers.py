def fib(n):
    if n==0:
        return [0, 1]
    p = fib(n>>1)
    c = p[0] * (2 * p[1] - p[0])
    d = p[0]**2 + p[1]**2
    c %= 1000000007
    d %= 1000000007
    if(n&1):
        return [d, c+d]
    else:
        return [c, d]

n = int(input())
x = fib(n)
print(x[0]%1000000007)