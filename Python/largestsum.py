f = open("input.txt",'r')
sum = 0
for i in f.readlines():
    sum += int(i)
print(str(sum)[0:10])

