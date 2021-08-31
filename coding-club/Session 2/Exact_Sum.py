# https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1998

def binarySearch(arr,k):
    left = 0
    right = len(arr)-1
    while (left<=right):
        mid = int((left+right)/2)
        if arr[mid]==k:
            return True
        elif arr[mid]<k:
            left = mid + 1
        else:
            right = mid - 1
    return False

while True:
    try:
        N = int(input())
    except:
        break
    arr = list(map(int,input().split()))
    M = int(input())
    arr.sort()
    # print(arr) # Prints the sorted array.
    ans = []
    for i in range(N):
        if(arr[i]>(M/2)):
            break
        if(binarySearch(arr[i+1:N],M-arr[i])):
            ans.append(arr[i])
    # print(ans) # Prints the lower price values of books in increasing order
    print(f"Peter should buy books whose prices are {ans[-1]} and {M-ans[-1]}.\n")
    dispose = input()
