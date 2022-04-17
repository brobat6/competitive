n = int(input())
cuts = [0, 360]
current = 0
arr = list(map(int, input().split()))
for i in arr:
    current = (current + i) % 360
    cuts.append(current)
cuts.sort()
angle = 0
for i in range(len(cuts) - 1):
    angle = max(angle, cuts[i + 1] - cuts[i])
print(angle)