nums = []
for i in range(10,1000000):
    s = str(i)
    tot = 0
    for j in s:
        tot += int(j)**5
    if tot   == i:
        nums.append(i)
print(nums)
print(sum(nums))