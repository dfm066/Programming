import itertools

primes = [1,2,3,5,7,11,13,17]
pansum = 0
for pan in itertools.permutations(range(10)):
        flg = True
        for i in range(1,8):
            num = 0
            for j in range(3):
                num = num*10 + int(pan[i+j])
            if num % primes[i] != 0:
                flg = False
        if flg:
            val = 0
            for i in pan:
                val = val*10 + int(i)
            pansum += val
print(pansum)