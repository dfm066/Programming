rom = {'I': 1, 'V': 5, 'X' : 10, 'L' : 50, 'C' : 100, 'D': 500, 'M' : 1000}
# rom = { 1 : 'I', 5 : 'V', 10 : 'X', 50 : 'L', 100 : 'C', 500 : 'D', 1000 : 'M'}
def convertToDecimal(num)->int:
    no = 0
    for j in range(0, len(num) - 1):
        if rom.get(num[j]) < rom.get(num[j + 1]):
            no -= int(rom.get(num[j]))
        else:
            no += int(rom.get(num[j]))
    no += int(rom.get(num[-1]))
    # print(no)
    return no
def convertToRoman(num)->str:
    digit = []
    m = d = c = l = x = v = i = 0
    if num//1000>0:
        m = num//1000
        num %= m*1000
    if num//500>0:
        d = num//500
        num %= 500
    if num // 100 > 0:
        c = num // 100
        num %= c*100
    if num // 50 > 0:
        l = num // 50
        num %= 50
    if num //10 > 0:
        x = num // 10
        num %= x * 10
    if num // 5 > 0:
        v = num // 5
        num %= 5
    if num // 1 > 0:
        i = num
        num %= i
    num = ''
    for j in range(0,m):
        num += 'M'
    if d == 1 and c == 4:
        num += 'CM'
    elif d == 0 and c ==4:
        num += 'CD'
    else:
        for j in range(0, d):
            num += 'D'
        for j in range(0, c):
            num += 'C'
    if l == 1 and x ==4:
        num += 'XC'
    elif l == 0 and x == 4:
        num += 'XL'
    else:
        for j in range(0, l):
            num += 'L'
        for j in range(0, x):
            num += 'X'
    if v == 1 and i == 4:
        num += 'IX'
    elif v == 0 and i == 4:
        num += 'IV'
    else:
        for j in range(0, v):
            num += 'V'
        for j in range(0, i):
            num += 'I'
    # print(m, d, c, l, x, v, i, sep=' ')
    return num

def main():
    f = open('roman.txt')
    o = open('roman_out.txt', 'w')
    nf = open('new_roman.txt','w')
    diff = 0
    for lines in f:
        if (lines[-1] == '\n'):
            lines = lines[:-1]
        old_no = convertToDecimal(lines)

        new_no = convertToRoman(old_no)
        diff += len(lines)-len(new_no)
        nf.write(new_no+'\n')
        o.write(str(old_no)+'\n')
    print(diff)
main()

