import math
import time


def divisor(n) -> int:
    div = []
    if n > 1:
        div.append(1)
        div.append(n)
    if (math.sqrt(n) % 1 == 0):
        div.append(math.sqrt(n))
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0 and n / i > i:
            div.append(i)
            div.append(n//i)
    count = len(div)
    return count

# print("No of divisors : {0}".format(divisor(31351320)))

def main():
    print("Input divisor count : ")
    max = int(input())
    t = time.time()
    tri_num = 0
    div = 0
    for i in range(max, max*max):
        tri_num = i*(i+1)/2
        divCount = divisor(tri_num)
        if divCount > max:
            break
    print("Triangular number with divisors greater than {0} is {1}th :  {2} \nCompleted in {3}".format(max,i,tri_num,time.time()-t))


main()
