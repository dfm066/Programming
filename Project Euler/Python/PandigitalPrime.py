import math


def primes(n):
    sieve = [True] * n
    for i in range(3, int(n ** 0.5) + 1, 2):
        if sieve[i]:
            sieve[i * i::2 * i] = [False] * ((n - i * i - 1) // (2 * i) + 1)
    return [2] + [i for i in range(3, n, 2) if sieve[i]]


def form_num(arr):
    curr = 0
    for i in arr:
        curr = curr * 10 + i
    return curr


def check_prime(num):
    for i in primeNums:
        if i <= math.sqrt(num):
            if num % i == 0:
                return False
        else:
            return True
    return True


def next_permutation(arr):
    # Find non-increasing suffix
    i = len(arr) - 1
    while i > 0 and arr[i - 1] <= arr[i]:
        i -= 1
    if i <= 0:
        return False

    # Find successor to pivot
    j = len(arr) - 1
    while arr[j] >= arr[i - 1]:
        j -= 1
    arr[i - 1], arr[j] = arr[j], arr[i - 1]

    # Reverse suffix
    arr[i:] = arr[len(arr) - 1: i - 1: -1]
    return True


digc = 7
primeNums = primes(int(math.sqrt(10 ** digc)) + 1)

for i in range(digc, 0, -1):
    num = []
    for j in range(i, 0, -1):
        num.append(j)
    curr = form_num(num)
    if check_prime(curr):
        print(curr)
        break
    flg = False
    while next_permutation(num):
        curr = form_num(num)
        if check_prime(curr):
            print(curr)
            flg = True
            break
    if flg:
        break
