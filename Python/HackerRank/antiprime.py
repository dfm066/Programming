<<<<<<< HEAD
import math
def isPrime(n)->bool:
    if n < 2:
        return False
    for i in range(2,int(math.sqrt(n))+1):
        if n % i == 0:
            return False
    return True
prime = []
f = open('..\prime.txt','r')
for i in f:
    prime.append(int(i[:-1]))

def divisor(n) -> int:
    div = 1
    factors = set()
    step = 0
    cnt = 0
    lim = len(prime)
    while n > 1 and step < lim:
        if n % prime[step] == 0:
            factors.add(prime[step])
            cnt += 1
            n //= prime[step]
        else:
            step += 1
            div *= (1+cnt)
            cnt = 0
    step += 1
    div *= (1 + cnt)
    return div

antiprime = []
for i in range(1, 21):
    antiprime.append(divisor(i))
print(antiprime)
# q = int(input())
# for i in range(0,q):
#     a = int(input())
#     if max(antiprime[:a]) < antiprime[a]:
#         print(a)
#     else:
#         lim = max(antiprime[:a])
#         i = a+1
#         while antiprime[i] <= lim:
#             i += 1
#         print(i)

=======
import math
def isPrime(n)->bool:
    if n < 2:
        return False
    for i in range(2,int(math.sqrt(n))+1):
        if n % i == 0:
            return False
    return True
prime = []
f = open('..\prime.txt','r')
for i in f:
    prime.append(int(i[:-1]))

def divisor(n) -> int:
    div = 1
    factors = set()
    step = 0
    cnt = 0
    lim = len(prime)
    while n > 1 and step < lim:
        if n % prime[step] == 0:
            factors.add(prime[step])
            cnt += 1
            n //= prime[step]
        else:
            step += 1
            div *= (1+cnt)
            cnt = 0
    step += 1
    div *= (1 + cnt)
    return div

antiprime = []
for i in range(1, 21):
    antiprime.append(divisor(i))
print(antiprime)
# q = int(input())
# for i in range(0,q):
#     a = int(input())
#     if max(antiprime[:a]) < antiprime[a]:
#         print(a)
#     else:
#         lim = max(antiprime[:a])
#         i = a+1
#         while antiprime[i] <= lim:
#             i += 1
#         print(i)

>>>>>>> origin/master
