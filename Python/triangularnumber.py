import math
import time




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
