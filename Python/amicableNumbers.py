import math
import time

t = time.time()
def divisorSum(n) -> int:
    div = []
    divSum = 0
    if n > 1:
        div.append(1)
    if (math.sqrt(n) % 1 == 0):
        div.append(math.sqrt(n))
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0 and n / i > i:
            div.append(i)
            div.append(n//i)
    divSum = sum(div)
    return divSum

def main():
    amicableNum = []
    for i in range(1,10001):
        tmp = divisorSum(i)
        if i==divisorSum(tmp) and i != tmp:
            amicableNum.append(i)
            amicableNum.append(tmp)
    amicableNum = set(amicableNum)
    print(sum(amicableNum))
main()




