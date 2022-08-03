n = int(input())
l = len(str(n))
ans = 0
for i in range(l - 1):
    x = 9 * (10 ** i)
    ans += (x * (x + 1))//2
x = (n - 10**(l - 1) + 1)
ans += x * (x + 1) // 2
print(ans % 998244353)