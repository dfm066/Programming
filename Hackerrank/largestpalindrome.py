def solution() -> str:
    i = 999
    palindromes = []
    for j in range(0, 900):
        for k in range(0, j):
            a = (i - k)
            b = (i - j)
            if len(str(a)) == 3 and len(str(b)) == 3:
                product = (i - k) * (i - j)
                if str(product) == str(product)[::-1]:
                    if 101101 <= product <= 1000000:
                        palindromes.append(product)
    palindromes.sort()
    print(palindromes)
    limit = len(palindromes)
    t = int(input())
    for tc in range(t):
        n = int(input())
        i = limit - 1
        while i >= 0 and palindromes[i] < n:
            i -= 1
        print(palindromes[i - 1])


solution()
