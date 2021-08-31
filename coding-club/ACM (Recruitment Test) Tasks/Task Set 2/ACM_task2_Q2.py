def func(i):
	left_index = grid.index(list(filter(lambda k: k >= grid[i], grid))[0])
	right_index = gridRev.index(list(filter(lambda k: k >= grid[i], gridRev))[0])
	right_index = n - right_index
	return (grid[i]*abs((right_index-left_index-1)))

n = int(input())
grid = list(map(int,input().split()))
gridRev = [i for i in reversed(grid)]
max_area = 0
for i in range(n):
	area = func(i)
	max_area = max(area,max_area)
print(max_area)