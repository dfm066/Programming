T = int(input())
while T > 0:
    T -= 1
    N = int(input())
    sum = 0
    num = 2
    while num < N:
        sum += num
        num = int(round(num*4.236068,0))
    print(sum)