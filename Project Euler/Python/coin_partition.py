# 
# Let p(n) represent the number of different ways in which n coins can be separated into piles. For example, five coins can be separated into piles in exactly seven different ways, so p(5)=7.

# OOOOO
# OOOO   O
# OOO   OO
# OOO   O   O
# OO   OO   O
# OO   O   O   O
# O   O   O   O   O
# Find the least value of n for which p(n) is divisible by one million.

#

import math

p = [1, 1, 2, 3]              # partition vector
d = [0, 1, 3, 4]              # sigma vector

def partitions(n):
    parts = 0
    st = -int((int(math.sqrt(24*n+1)) - 1)/6)
    en = int((int(math.sqrt(24*n+1)) + 1)/6)
    for k in range(st,en+1) :
        if k == 0:
            continue
        sign = (-1)**(abs(k) - 1)
        coff =  int(k * (3 * k - 1) / 2)
        if (n - coff >= 0):
            parts += sign * p[n-coff]
    
    p.append(parts)
    return parts

def p78():
    limit = 1000000
    curr_part = 3
    n = 3
    while curr_part % limit != 0:
        n = n + 1
        curr_part = partitions(n)
    print("Answer : {0} - {1} ".format(n, curr_part)) 
    return n

print("Answer : {0}".format(p78())) 