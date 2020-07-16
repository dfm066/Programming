def number_histo(num):
    d = [0]*10
    while num > 0:
        d[num%10] += 1
        num //= 10
    return "-".join(str(x) for x in d)

def p62(limit):
    table = dict()
    for i in range(1, 10000):
        key = number_histo(i**3)
        if key in table:
            table[key].append(i**3)
        else:
            table[key] = [i**3]
    for _, val in table.items():
        if len(val) == limit:
            print(val)
p62(5)
    