import math

num = 9
x = 0
def isNotPrime(n)->bool:
    if n < 2:
        return True
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return True
    return False

while True:
    if isNotPrime(num):
        for i in range(1,int(math.sqrt(num))):
            x = num - 2*i*i
            if not isNotPrime(x):
                break
    if isNotPrime(x):
        break
    num += 2
print(num)