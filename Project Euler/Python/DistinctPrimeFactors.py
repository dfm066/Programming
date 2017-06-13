import time

def nprimes(n):
    """ Returns  a list of primes < n """
    sieve = [True] * n
    for i in range(3,int(n**0.5)+1,2):
        if sieve[i]:
            sieve[i*i::2*i]=[False]*((n-i*i-1)//(2*i)+1)
    return [2] + [i for i in range(3,n,2) if sieve[i]]

def numberOfPrimeFactors(n):
    factors = 0
    i = 0
    for i in primes:
        check = False
        while n % i == 0:
            check = True
            n //= i
        if check:
            factors += 1
        if n == 1:
            return factors
    return factors

t1 = time.clock()
primes = nprimes(1000000)
t2 = time.clock()
print(f"Prime sieve built in {t2-t1} secs")
start = 2 * 3 * 5 *7
w_size = 4
it = 0
factors = [None]*w_size
ans = 0

while it < 4:  
    if numberOfPrimeFactors(start) == w_size:
        it += 1
    else:
        it = 0 
    start += 1
t3 = time.clock()
print(f"Ans : {start-w_size+1} found in {t3-t1} secs")