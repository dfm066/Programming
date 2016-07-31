import math
def isPrime(n)->bool:
    if n < 2:
        return False
    for i in range(2,int(math.sqrt(n))+1):
        if n % i == 0:
            return False
    return True
def main():
    cprime = []
    for i in range(1,1000000):
        if isPrime(i):
            s = []
            s.append(i)
            tmp = str(i)
            length = len(tmp)
            for j in range(1,len(tmp)):
                tmp = tmp[length-1:]+tmp[:length-1]
                if isPrime(int(tmp)):
                    s.append(int(tmp))
            if len(s) == len(str(i)):
                cprime.append(i)
    # cprime = sorted(cprime)
    # print(cprime)
    print(len(cprime))
main()