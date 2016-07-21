def Solution(num) :
    i = 1
    for k in range(1, num+1):
        if i % k > 0:
            for j in range(1, num+1):
                if (i * j) % k == 0:
                    i *= j
                    break
    return i

print(Solution(20))
