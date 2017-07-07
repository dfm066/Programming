import time,math
from utils import utils
from fractions import gcd

N = int(input())

t_ = time.time()
done_map = [N-1] * (N-1)
distinct = 0
it = 0
for i in range(2, N+1):
    j = i*i
    exp = 2
    while j <= N:
        #done_map[j-2] -= (N // exp - 1)
        for k in range(2, exp+1):
            if exp % k != 0:
                d = k * exp // gcd(k, exp)
                done_map[j-2] -= (k * N // d - (k-1) * N // d)  
        exp += 1 
        j *= i
        print(i," ",exp," ",done_map)
for i in range(N-1):
    if done_map[i] < 0:
        done_map[i] = 0
print(sum(done_map))
print(done_map)
print('Time taken = ', time.time() - t_,' seconds.')

sol = set()
red = [N-1] * (N-1) 
for i in range(2, N+1):
    for j in range(2, N+1):
        if i**j in sol:
            red[i-2] -= 1
        else:
            sol.add(i**j)
print(len(sol))
print(red)