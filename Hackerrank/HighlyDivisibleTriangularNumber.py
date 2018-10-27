import math
import time

primes = []
primes.append(2)
cnt = 1
num = 3
limit = 10
while cnt < 10000:
    flg = True
    for i in range(2, int(math.sqrt(num)) + 1):
        if num % i == 0:
            flg = False
            break
    if flg:
        cnt += 1
        primes.append(num)
    num += 2


def divisor(n) -> int:
    div = 1
    cnt = 0
    tmp = n
    p = primes[0]
    while tmp > 1 and p <= int(math.sqrt(n)) + 1:
        cnt = 0
        while tmp % p == 0:
            cnt += 1
            tmp //= p
        div *= (1 + cnt)
        p += 1
    if tmp > 2:
        div *= 2
    return div


tri_num = [0 for i in range(limit+1)]
curr = 0
i = 1
num = 0
divc = 0
while curr < limit:
    num += i
    if i & 1:
        divc = divisor(i) * divisor((i+1)//2)
    else:
        divc = divisor(i//2) * divisor(i+1)
    if divc > curr:
        if divc > limit:
            bound = limit
        else:
            bound = divc
        for j in range(curr,bound+1):
            tri_num[j] = num
        curr = divc
    i += 1
print(tri_num)
t = int(input())
for tc in range(t):
    n = int(input())
    print(tri_num[n])

