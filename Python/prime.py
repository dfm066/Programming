<<<<<<< HEAD
import math
def isPrime(n)->bool:
    if n < 2:
        return False
    for i in range(2,int(math.sqrt(n))+1):
        if n % i == 0:
            return False
    return True

f = open("prime.txt",'w')
f.write('2\n')
for i in range(3, 10000001,2):
    if (isPrime(i)):
=======
import math
def isPrime(n)->bool:
    if n < 2:
        return False
    for i in range(2,int(math.sqrt(n))+1):
        if n % i == 0:
            return False
    return True

f = open("prime.txt",'w')
f.write('2\n')
for i in range(3, 10000001,2):
    if (isPrime(i)):
>>>>>>> origin/master
        f.write(str(i)+'\n')