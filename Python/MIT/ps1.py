import math

# Problem 1
def prime_series(n)->[]:
    x = []
    i = 0
    x.append(2)
    test=3
    while i != n:
        flg = 1
        for j in range(2,int(math.sqrt(test))+1):
            if test%j == 0:
                flg = 0
                break
        if flg == 1:
            x.append(test)
        test += 2
        i += 1
    return x

##series = prime_series(int(input()))
##for i in series:
##    print("{0} ".format(i))

#############################################

# Problem 2

def calcSum(n):
    series = prime_series(n)
    sum = 0
    for i in series:
        if i>n:
            break
        sum += math.log(i)
    print("{0} {1} {2}".format(sum,n,sum/n))

calcSum(int(input()))
