n, k = map(int, input().split())
p = list(map(int, input().split()))
q = list(map(int, input().split()))
r = [0] * (n)
for i in range(n):
    r[p[i] - 1] = q[i]
MOD = 998244353
dp = [[0 for i in range(k + 1)] for j in range(n + 1)]
# dp[i][j][k] --> Assuming last i values have been checked, the largest
# value so far that has been skipped is j, and k values have been chosen so far.
dp[n][0] = 1
for i in range(n):
    x = r[i] - 1
    ndp = [[0 for z in range(k + 1)] for j in range(n + 1)]
    for j in range(0, n + 1):
        for z in range(0, k + 1):
            # Skipped x
            ndp[min(j, x)][z] += dp[j][z]
            ndp[min(j, x)][z] %= MOD
    for j in range(x + 1, n + 1):
        for z in range(1, k + 1):
            # Included x
            ndp[j][z] += dp[j][z - 1]
            ndp[j][z] %= MOD
    dp = ndp
ans = 0
for i in range(0, n + 1):
    ans += dp[i][k]
    ans %= MOD
print(ans)