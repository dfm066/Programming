facts = [1]
fact = 1
for i in range(1,100001):
    fact *= i
    fact %= 1000000007
    facts.append(fact)
T = int(input())
letters = []
for i in range(0,26):
    letters.append(0)

while T > 0:
    T -= 1
    s = input()
    cnt = 0
    ans = 1
    for i in s:
        letters[ord(i)-97] += 1
    for i in letters:
        if i != 0:
            cnt += 1
            ans = ans*facts[i]
    ans = ans*facts[cnt]%1000000007
    for i in range(0, 26):
        letters[i] = 0;
    print(ans)
