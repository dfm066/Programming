import time

def primes2n(n):
    sieve = [True] * n
    for i in range(3, int(n ** 0.5) + 1, 2):
        if sieve[i]:
            sieve[i * i::2 * i] = [False] * ((n - i * i - 1) // (2 * i) + 1)
    return [2] + [i for i in range(3, n, 2) if sieve[i]]

def isPandigitalNum(num)->bool:
    digit = set()
    for i in num:
        if i == '0':
            return False
        digit.add(i)
    if len(digit) == len(num):
        return True
    return False

t = time.clock()
primes = primes2n(10**10)
print(t - time.clock())
T = int(input())

while T != 0:
    T -= 1
    N = int(input())
    low = 0
    high = len(primes)
    mid = low+high // 2
    while low < high:
        if primes[mid] == N:
            break
        elif primes[mid] < N:
            low = mid + 1
            mid = low+high // 2
        else:
            high = mid - 1
            mid = low+high // 2
        print(mid)
    