N, K = map(int, input().split())
travel_index = list(map(int, input().split()))

input_count = 0 

num_to_city ={}
city_to_num ={}
 
index=0
dicts={}
count=1
num_to_city[0] = 1
city_to_num[1] = 0
 
while travel_index[index] not in city_to_num:
    num_to_city[count] = travel_index[index]
    city_to_num[travel_index[index]] = count
    
    index = travel_index[index]-1
    count += 1
num_to_city[count] = travel_index[index]
 
final_repeat_town_index = max(num_to_city.keys())
 
first_repeat_town = num_to_city[final_repeat_town_index]
 
first_repeat_town_index = city_to_num[first_repeat_town]
 
if K-first_repeat_town_index>0:
    nums = (K - first_repeat_town_index) % (final_repeat_town_index - first_repeat_town_index)
    print(num_to_city[first_repeat_town_index+nums])
else:
    print(num_to_city[K])