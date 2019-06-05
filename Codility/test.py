import math
cur_val = 0
cur_p = 0
prev_val = 0
while cur_val < 10**6:
    prev_val = cur_val
    cur_val += 2**cur_p
    cur_p += 1
    print (str(cur_val) + " " + str(cur_p-1) + " " + str(prev_val))