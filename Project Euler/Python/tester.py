import math

def nthPentagon(n):
    return n * (3*n -1) // 2

def isPentagon(x):
    n = ( 1 + int( math.sqrt(1+24*x) ) ) // 6
    return nthPentagon(n) == x

N, K = input().split(" ")
N = int(N)
K = int(K)
currN = K
currNK = 1

while currN < N:
    currN += 1
    Pn = nthPentagon(currN)
    currNK = currN - K
    Pnk = nthPentagon(currNK)
    if isPentagon(Pn + Pnk) or isPentagon(Pn-Pnk):
        print(Pn)
