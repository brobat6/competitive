def NotRepeat():
    ''' To generate the sequence of towns being travelled.
    As soon as a town is stumbled upon a second time, the function is terminated.'''
    global modulo_factor
    global first_repeat_town
    global first_repeat_town_index
    boolean = True
    for i in range(len(towns_travelled)):
        for j in range(len(towns_travelled)):
            if (i!=j) and towns_travelled[i]==towns_travelled[j]:
                modulo_factor = abs(i-j)
                first_repeat_town = towns_travelled[i]
                first_repeat_town_index = min(i,j) 
                boolean = False
                break
    return boolean

N,K = input().split()
N = int(N)
K = int(K)
travel_index = list(map(int, input().split()))
towns_travelled = []
current_town = 1

while NotRepeat():
    towns_travelled.append(current_town)
    current_town = travel_index[current_town-1]

K = (K - first_repeat_town_index) % modulo_factor
print(towns_travelled[first_repeat_town_index+K])


'''
Sample Input 
6 727202214173249351
6 5 2 5 3 2
'''