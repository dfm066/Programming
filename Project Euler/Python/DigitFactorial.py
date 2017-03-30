fact = [1]
sum = 0
for i in range(1,10):
    fact.append(fact[-1] * i)
for i in range(10, 1000000):
    partsum = 0
    for j in str(i):
        partsum += fact[int(j)]
    if partsum == i:
        sum += i
        print(i)
print(fact[9])
print(sum)
