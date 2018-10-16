num = []
limit = 1000000
for i in range(limit):
    num.append(False)
primes = []
i = 2
while i < limit:
    primes.append(i)
    j = 1
    while i*j < limit:
        num[i*j] = True
        j += 1
    while i < limit and num[i]:
        i += 1
t = int(input())
for tc in range(t):
    n = int(input())
    print(primes[n-1])
