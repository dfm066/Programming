limit = 5000000
collatz = {1:1}
tmp = []
num = 0
for i in range(2, limit+1):
    if i not in collatz:
        tmp.clear()
        num = i
        while num != 1:
            if num not in collatz:
                tmp.append(num)
                if num & 1:
                    num = num*3+1
                else:
                    num //= 2

            else:
                break
    for j in range(0, len(tmp)-1):
            # if tmp[j] <= limit:
        collatz[tmp[j]] = len(tmp[j:]) + collatz[num]
print(len(collatz))
# print(collatz)
print(max(collatz.keys()))
# t = int(input())
# for tc in range(t):
#     n = int(input())
#     m = 0
#     num = 0
#     for i in range(1, n+1):
#         if m <= collatz[i]:
#             m = collatz[i]
#             num = i
#     print(num)
