N = 600851475143
n = N
i = 2

factors = []

while i <= n:
    if n%i == 0:
        factors.append(i)
        n = n // i
        i=2
    i+=1

print(factors)
