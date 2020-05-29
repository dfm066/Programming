N = int(input())
sum = 0
sieve = [True] * (N+1)
n = N+1
for i in range(3,int(n**0.5)+1,2):
    if sieve[i]:
        sieve[i*i::2*i]=[False]*((n-i*i-1)//(2*i)+1)
primes = [2] + [i for i in range(3,n,2) if sieve[i]]
sieve = [False] * (N+1)
for i in primes:
    sieve[i] = True
for i in range(2,N):
        if sieve[i]:
            counter = 1
            tmp = str(i)
            length = len(tmp)
            for j in range(1,len(tmp)):
                tmp = tmp[length-1:]+tmp[:length-1]
                if sieve[int(tmp)]:
                    counter += 1
            if counter == length:
                sum += 1
print(sum)