import math

class utils:
    def nprimes(n):
        """ Returns  a list of primes < n """
        sieve = [True] * n
        for i in range(3,int(n**0.5)+1,2):
            if sieve[i]:
                sieve[i*i::2*i]=[False]*((n-i*i-1)//(2*i)+1)
        return [2] + [i for i in range(3,n,2) if sieve[i]]

    def nthprime(n):
        num = 1
        primes = [2]
        if n == 1:
            return 2
        while n > 1 :
            num += 2
            limit = int(math.sqrt(num))+1
            for i in primes:
                if i > limit:
                    primes.append(num)
                    n -= 1
                    break
                if num % i == 0 :
                    break
                
            if i == primes[-1]:
                primes.append(num)
                n -= 1
        return num