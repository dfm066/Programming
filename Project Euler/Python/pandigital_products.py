def isPandigitalProduct(s)->bool:
    digit = set()
    chk = 0
    for i in s:
        chk += len(i)
        for j in i:
            if j == '0':
                return False
            digit.add(j)
    # print(digit)
    if len(digit) == 9 and len(digit) == chk:
        return True
    return False

def isPandigitalNum(num)->bool:
    digit = set()
    for i in num:
        if i == '0':
            return False
        digit.add(i)
    if len(digit) == len(num):
        return True
    return False

def main():
    prod = set()
    for i in range(100,10000):
        if isPandigitalNum(str(i)):
            for j in range(1,99):
                if isPandigitalNum(str(j)):
                   if isPandigitalNum(str(i*j)):
                       if isPandigitalProduct([str(i),str(j),str(i*j)]):
                           tmp = i*j
                           prod.add(tmp)
                           print(i,j,tmp)
    print(prod)
    print(sum(prod))

# print(isPandigitalProduct(['396','79',str(396*79)]))
main()
