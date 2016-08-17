import math
def abundant(n)->int:
    div = []
    divSum = 0
    if n > 1:
        div.append(1)
    if (math.sqrt(n) % 1 == 0):
        div.append(math.sqrt(n))
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0 and n / i > i:
            div.append(i)
            div.append(n // i)
    divSum = sum(div)
    if divSum > n:
        return True
    else:
        return False

abundantNums = []
for i in range(12,28123):
    if abundant(i):
        abundantNums.append(i)
abundantNums.sort()
print(abundantNums,len(abundantNums),sep='\n')
cnt = 0
x = 0
sumOfAbundant = []
for i in abundantNums:
    if i > 28111:
        break
    for j in abundantNums[x:]:
        if i+j > 28123:
             break
        elif i+j ==28123:
            print(i,j)
        cnt += 1
        sumOfAbundant.append(i+j)
    x += 1
sumOfAbundant = set(sumOfAbundant)
nonAbundantSum =[]
for i in range(1,28124):
    if i not in sumOfAbundant:
        nonAbundantSum.append(i)
print(sum(nonAbundantSum))

