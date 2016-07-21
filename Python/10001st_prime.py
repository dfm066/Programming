import time
import math
import sys


def nthprime(num):
    n = 1
    if num == 1:
    	return 2
    while num > 1 :
        i = 2
        n += 2
        limit = int(math.sqrt(n))+1
        while i < limit:
            if n % i == 0 :
                break
            i += 1
        if i == limit:
            num -= 1
    return n

num = int(input())
t_ = time.time()
print("Prime {0}: {1}".format(num,nthprime(num)))
    print('Time taken = ', time.time() - t_,' seconds.')
input()

