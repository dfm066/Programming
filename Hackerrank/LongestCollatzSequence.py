import time
t= time.time()
limit = 5000000
collatz = {1:1,0:0}
tmp = []
num = 1
cnt = 0
while 2*num <= limit:
    collatz[2*num] = collatz[num] + 1
    num *= 2
for i in range(3,limit+1):
    if i & 1 and i not in collatz:
        tmp.clear()
        num = i
        while num != 1 and num not in collatz:
            tmp.append(num)
            if num & 1:
                num = (num*3+1)//2
            else:
                num >>= 1
        tmp.append(num)
        bound = len(tmp)-1
        # print(tmp)
        # input()
        for j in range(bound-1, -1, -1):
            # if tmp[j] <= limit:
            if tmp[j] & 1:
                collatz[tmp[j]] = collatz[tmp[j+1]] + 2
            else:
                collatz[tmp[j]] = collatz[tmp[j + 1]] + 1
            k = tmp[j]
            while 2*k <= limit:
                collatz[2*k] = 1+collatz[k]
                k *= 2
                cnt += 1

print(len(collatz))
print(max(collatz.values()))
print(time.time()-t)
ans = []
curr_max = 0
curr = 0
for i in range(0,limit+1):
    if curr_max < collatz[i]:
        curr_max = collatz[i]
        curr = i
    ans.append(curr)
t = int(input())
for tc in range(t):
    n = int(input())
    print(ans[n])

