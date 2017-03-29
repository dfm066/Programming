def factorial(num):
    fact = 1
    for i in range(2,num+1):
        fact *= i
    return fact


def main():
    facts = []
    sum  = 0
    len = 2
    for i in range(0,10):
        facts.push(factorial(i))
    for i in range(10, 10000):
        partsum = 0
        for j in str(i):
            partsum += facts[int(j)]
        if partsum == i:
            sum += i
    print("Sum :  {0}".format(sum))

main()
