n=int(input())
l=sorted([(int(i),k+1) for (k,i) in enumerate(input().split())], key=lambda a:(-a[0],a[1]))
done=False
if l[0][0]-l[1][0]>1:
    print(-1)
    done = True
if not done:
    while l[0][0] != 0:
        print(l[0][1], end=' ')
        l[0] = (l[0][0]-1,l[0][1])
        k=l[1][0]
        if k!=0:
            print(*(x:=sorted([i[1] for i in l[1:] if i[0]==k])), end=' ')
            for i in range(len(x)): l[i+1] = (l[i+1][0]-1,l[i+1][1])