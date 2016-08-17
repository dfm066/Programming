def isPandigitalProduct(s)->bool:
    digit = set()
    chk = 0
    for i in s:
        if i == '0':
            return False
        digit.add(i)
    # print(digit)
    if len(digit) == 9 and len(s) == 9:
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
    max = 0
    for i in range(2,100000):
        if isPandigitalNum(str(i)):
            s = str(i)
            if s[0] == '9':
                j = 2
                while True:
                    if len(s) == 9:
                        break
                    if isPandigitalNum(str(i*j)):
                        s += str(i*j)
                        j += 1
                    else:
                        break
                if isPandigitalProduct(s):
                    if max < int(s):
                        max = int(s)
                        print(i)
    print(max)
main()