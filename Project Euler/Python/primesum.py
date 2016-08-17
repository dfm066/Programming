import math


def primeSum(n):
    sum = 2
    if(n<2):
        return 0
    if (n % 2 == 0):
        n -= 1
    while n > 2:
        flg = 0
        for i in range(2, int(math.sqrt(n)) + 1):
            if n % i == 0:
                flg = 1
                break
        if flg != 1:
            sum += n
        n -= 2
    return sum


print("{0}".format(primeSum(int(input()))))
