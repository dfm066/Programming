MAX = 100000
coins = [1, 2, 5, 10, 20, 50, 100, 200]
ways = [0] * (MAX+1)
ways[0] = 1
for coin in coins:
    for j in range(coin, MAX+1):
        ways[j] += ways[j - coin]

T = int(input())
while T != 0:
    N = int(input())
    print(ways[N])
    T -= 1