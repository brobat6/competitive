n, q = map(int, input().split())

adj = list()
for i in range(n + 1):
    adj.append(list())

visited = [False] * (n + 1)

for i in range(q):
    a, b = map(int, input().split())
    adj[a - 1].append(b)
    adj[b].append(a - 1)

q = list()
qptr = 0
q.append(0)
visited[0] = True

while(qptr < len(q)):
    curr = q[qptr]
    qptr += 1
    for next in adj[curr]:
        if(visited[next] == False):
            q.append(next)
            visited[next] = True

print("Yes" if visited[n] else "No")