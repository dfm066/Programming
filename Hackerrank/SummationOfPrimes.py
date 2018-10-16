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
curr = 0
p = 0
pc = len(primes)
for i in range(limit):
    if p < pc and i == primes[p]:
        curr += i
        p += 1
    num[i] = curr
t = int(input())
for tc in range(t):
    n = int(input())
    print(num[n])