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

cnt = len(abundantNums)
num = (cnt*(cnt-1))//2
print(num)

