def solution() -> str:
    i = 999
    for j in range(0,99):
        for k in range(0,int(j/2)):
            product = str((i-k)*(i-j-k))
            if product == product[::-1]:
                return product

import time

tStart = time.time()
print (solution())
print (str((time.time() - tStart)))