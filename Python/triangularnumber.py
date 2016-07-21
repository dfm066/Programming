import math
import time

def divisor(n) -> int:
    if (math.sqrt(n) % 1 == 0):
        div = 3
    else:
        div = 2
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0 and n / i > i:
            div += 2
    return div


# print("No of divisors : {0}".format(divisor(31351320)))

def main():
    print("Input divisor count : ")
    max = int(input())
    t = time.time()
    tri_num = 0
    div = 0
    for i in range(max, max*max):
        tri_num = i*(i+1)/2
        div = divisor(tri_num)
        if div > max:
            break
    print("divisor greater than {0} is {1}th triangularnumber {2} \nCompleted in {3}".format(div,i,tri_num,time.time()-t))


main()
