import math

def nthPentagon(n):
    return n * (3*n -1) // 2

def isPentagon(x):
    n = ( 1 + int( math.sqrt(1+24*x) ) ) // 6
    return nthPentagon(n) == x

currK = 1
currJ = 0
found = False

while not found:
    currK += 1
    Pk = nthPentagon(currK)
    for currJ in range(1, currK):
        Pj = nthPentagon(currJ)
        if isPentagon(Pk + Pj) and isPentagon(Pk-Pj):
            found = True
            break
        
print("k = {0} \t j = {1}".format(currK,currJ))
print("Pk = {0} \t Pj = {1}".format(Pk,Pj))
print(Pk-Pj)
