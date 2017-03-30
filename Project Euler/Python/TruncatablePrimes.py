import math

def primes(n):
    sieve = [True] * n
    for i in range(3, int(n**0.5)+1,2):
        if(sieve[i]):
            sieve[i*i::2*i] = [False] *((n-i*i-1)//(2*i)+1)
    return {**{2:2},**{i:i for i in range(3,n,2) if sieve[i]}}

count = 11
num = 11
sum = 0
primeNums = primes(1000000)
while count != 0:
    if primeNums.get(num) is not None:
        trunc = num
        flg = True
        for i in range(1,len(str(num))):
            if primeNums.get(trunc // 10) is None:
                flg = False
                break
            trunc //= 10
           # print(trunc)
        if flg:
            trunc = num
            for i in range(len(str(num))+1, 0, -1):
                if primeNums.get(trunc % (10**i)) is None:
                    flg = False
                    break
                trunc %= 10**i
            #    print(trunc)
        if flg:
            print(num)
            sum += num
            count -= 1
    num += 2
print(sum)
print(primeNums.get(1))