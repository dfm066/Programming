T = int(input())

for i in range(0,T):
    N = int(input())
    sum = (3 * ((N - 1) // 3) * ((N + 2)/ 3))//2 + (5 * ((N - 1) // 5) * ((N + 4) // 5))//2 - (15 * ((N - 1) // 15) * ((N + 14) // 15))//2
    print(int(sum))
