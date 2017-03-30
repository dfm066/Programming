maxp = [0]*1001
currmax = 0
maxval = 0

for c in range(1,500):
    for b in range(1,c):
        for a in range(1,b):
            if a**2 + b**2 == c**2 and a+b+c <= 1000:
                maxp[a+b+c] += 1
            #    print("a : {0} b : {1} c : {2}".format(a,b,c))
            elif a**2 + b**2 > 1000**2:
                break
for i in range(1,1001):
    if maxp[i] > currmax:
        currmax = maxp[i]
        maxval = i
print(maxval)