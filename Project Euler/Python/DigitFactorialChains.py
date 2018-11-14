#   Author : dfm066
#   Problem : 74

# The number 145 is well known for the property that the sum of the factorial
# of its digits is equal to 145: 1! + 4! + 5! = 1 + 24 + 120 = 145
# Perhaps less well known is 169, in that it produces the longest chain of
# numbers that link back to 169; it turns out that there are only three such
# loops that exist:
# 169 → 363601 → 1454 → 169
# 871 → 45361 → 871
# 872 → 45362 → 872
# It is not difficult to prove that EVERY starting number will eventually get
# stuck in a loop. For example,
# 69 → 363600 → 1454 → 169 → 363601 (→ 1454)
# 78 → 45360 → 871 → 45361 (→ 871)
# 540 → 145 (→ 145)
# Starting with 69 produces a chain of five non-repeating terms, but the longest
# non-repeating chain with a starting number below one million is sixty terms.
# How many chains, with a starting number below one million, contain exactly
# sixty non-repeating terms?

import time

def fact_num(n):
    fact_table = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880]
    num = 0
    while n != 0:
        d = n % 10
        n //= 10
        num += fact_table[d]
    return num

def pe_74():
    cnt = 0
    for x in range (2, 1000001):
        chain = []
        num = x
        while num not in chain:
            chain.append(num)
            num = fact_num(num)
        if len(chain) == 60:
            cnt += 1
    print("Solution : ",cnt)

start = time.time()
pe_74()
print("Executed in {0}s".format(time.time() - start))