import math

def p100(limit):
    blue = 3
    red = 1
    b = blue
    r = red
    solution = 0
    while True:
        sqr = math.sqrt(r**2 * 8 + 1)
        if sqr == int(sqr) and int(sqr)&1:
            solution = (sqr + 1) // 2 + r
            if solution + r > limit:
                break
        nb = blue*b+red*r*8
        nr = blue*r+red*b
        b = nb
        r = nr
    print(int(solution))

p100(10**12)

# 707106783028
# 1000000002604

