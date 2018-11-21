#   Author : dfm066
#   Problem : 63

#   The 5-digit number, 16807=75, is also a fifth power.
#   Similarly, the 9-digit number, 134217728=89, is a ninth power.
#   How many n-digit positive integers exist which are also an nth power?

def pe_63():
    cnt = 0
    for x in range(9, 0, -1):
        y = 1
        while len(str(x ** y)) == y:
            cnt += 1
            y += 1
    print(cnt)

pe_63()