import itertools,time 

def nprimes(n):
    """ Returns  a list of primes < n """
    sieve = [True] * n
    for i in range(3,int(n**0.5)+1,2):
        if sieve[i]:
            sieve[i*i::2*i]=[False]*((n-i*i-1)//(2*i)+1)
    return [2] + [i for i in range(3,n,2) if sieve[i]]

t1 = time.clock()
primes = nprimes(10000)
it = 0
size = 4
grp = 3
ans = set()
for i in primes:
    if len(str(i)) == size:
        break
    it += 1

primes = primes[it:]

for i in primes:
    it = 0
    cnt = 0
    nums =[int(''.join(x)) for x in itertools.permutations(str(i))]
    for j in nums:
        if len(str(j)) < size:
            del nums[it]
        it += 1
    nums = sorted(set(nums))
    # nums = set(nums)
    it = 0
    for j in nums:
        for k in range(it+1, len(nums)):
            if j in primes and nums[k] in primes and nums[k] + abs(nums[k]-j) in primes and abs(nums[k]-j) == 3330:
                ans.add(str(j)+str(nums[k])+str(nums[k] + abs(nums[k]-j)))
        it += 1
ans = sorted(ans)
t2 = time.clock()
print(f"Ans : {ans} found in {t2-t1} secs")
