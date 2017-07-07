import math

class utils:
    def primes2n(n):
        """ Returns  a list of primes < n """
        sieve = [True] * n
        for i in range(3,int(n**0.5)+1,2):
            if sieve[i]:
                sieve[i*i::2*i]=[False]*((n-i*i-1)//(2*i)+1)
        return [2] + [i for i in range(3,n,2) if sieve[i]]
    
    def nprimes(n):
        return len(utils.primes2n(n))

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

    def prime_factors(n):
        i = 2
        factors = []
        if n % i == 0:
            factors.append(2)
        while n % i == 0:
            n //= i
        i += 1
        while i <= n:
            if n % i == 0:
                factors.append(i)
                n = n // i
                i = 1
            i += 2
        return factors
    
    def nfactors(n):
        return len(utils.prime_factors(n))

    def nthroot(num, n):
        u, s = num, num+1
        while u < s:
            s = u
            t = (n - 1) * s + num // pow(s, n-1)
            u = t // n
        return s
        if float(s) == num ** (1/n):
            return s
        else:
            return -1
