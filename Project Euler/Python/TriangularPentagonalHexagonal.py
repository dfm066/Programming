import math

def nthTriangular(n):
    return n * (n + 1) // 2

def isTriangular(x):
    n = ( -1 + int( math.sqrt(1+8*x) ) ) // 2
    return n if nthTriangular(n) == x else 0

def nthPentagon(n):
    return n * (3*n -1) // 2

def isPentagon(x):
    n = ( 1 + int( math.sqrt(1+24*x) ) ) // 6
    return n if nthPentagon(n) == x else 0

def nthHexagonal(n):
    return n * (2*n -1)

def isHexagonal(x):
    n = ( 1 + int( math.sqrt(1+8*x) ) ) // 4
    return n if nthHexagonal(n) == x else 0

startH = 143
currH = 0
found  = False
H = P = T = 0

while not found:
    startH += 1
    currH = nthHexagonal(startH)
    P = isPentagon(currH)
    T = isTriangular(currH)
    if  P != 0 and T != 0 :
        H = startH
        found = True

print("H : {0}\tP : {1}\tT : {2}".format(H,P,T))
print("Number is {0}".format(currH))