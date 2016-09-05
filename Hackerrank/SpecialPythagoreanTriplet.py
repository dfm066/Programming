def gcd(a,b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)
limit = 3001
triplet = []
cnt = 0
for i in range(limit):
    triplet.append(-1)
for m in range(1, 80):
    for n in range(1, m):
        if gcd(n, m) == 1:
            a = m ** 2 - n ** 2
            b = 2 * m * n
            c = m ** 2 + n ** 2
            k = 1
            while k * (a+b+c) < limit :
                if triplet[k * (a+b+c)] < k ** 3 * a * b * c:
                    triplet[k * (a+b+c)] = k ** 3 * a * b * c
                    cnt += 1
                k += 1
print(cnt)
# print(triplet)
t = int(input())
for tc in range(t):
    n = int(input())
    print(triplet[n])
