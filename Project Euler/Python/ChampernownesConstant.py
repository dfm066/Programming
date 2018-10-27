digc = [1,10,100,1000,10000,100000,1000000]
fraction = ""
prod = 1
for i in range(10**18):
    fraction += str(i)
for j in digc:
    prod *= int(fraction[j])
print(prod)