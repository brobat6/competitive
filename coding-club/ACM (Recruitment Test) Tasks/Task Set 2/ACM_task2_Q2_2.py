def func():
    if len(grid)==0 or len(arr)==0:
        return 0
    if grid[-1]>=arr[-1]:
        area = arr[-1] * abs(gridIndex[-1]-index[-1])
        max_area.append(area)
        arr.pop()
        index.pop()
        #print(area,arr,index,max_area)
    elif grid[-1]<arr[-1]:
        area = grid[-1] * abs(gridIndex[-1]-index[-1])
        max_area.append(area)
        grid.pop()
        gridIndex.pop()
        #print(area,grid,gridIndex,max_area)
    func()
    
n = int(input())
grid = list(map(int,input().split()))
gridIndex = []
for i in range(n):
    gridIndex.append(i)
arr = [grid[0]]
index = [0]
for i in range(1,n):
    if grid[i]>arr[-1]:
        arr.append(grid[i])
        index.append(i)
arr.reverse()
index.reverse()
#print(arr)
#print(index)
max_area = []
func()
print(max(max_area))