import numpy as np
import time
# def gen_prim_pyth_trips(limit=None):
#     u = np.mat(' 1  2  2; -2 -1 -2; 2 2 3')
#     a = np.mat(' 1  2  2;  2  1  2; 2 2 3')
#     d = np.mat('-1 -2 -2;  2  1  2; 2 2 3')
#     uad = np.array([u, a, d])
#     m = np.array([3, 4, 5])
#     while m.size:
#         m = m.reshape(-1, 3)
#         if limit:
#             m = m[m[:, 2] <= limit]
#         yield from m
#         m = np.dot(m, uad)
# def gen_all_pyth_trips(limit):
#     for prim in gen_prim_pyth_trips(limit):
#         i = prim
#         for _ in range(limit//prim[2]):
#             yield i
#             i = i + prim

# N = int(input())
# t = time.clock()
# triples = list(gen_prim_pyth_trips(N // 2))
# print(len(triples))
# print(time.clock() - t)
# p = [0] * (N+1)
# for i in triples:
#     sum = i[0] + i [1] + i[2]
#     mult = 1
#     while sum * mult <= N:
#         p[sum * mult] += 1
#         mult += 1
# maxp = [0] * (N+1)
# counter = 0
# curr_max = 0
# curr_p = 0
# for i in p:
#     if curr_max < i:
#         curr_max = i
#         curr_p = counter
#     maxp[counter] = curr_p
#     counter += 1
# print(time.clock() - t)
# T = int(input())
# while T != 0:
#     T -= 1
#     N = int(input())
#     print(maxp[N])

m = np.array([3, 4, 5])
while m.size:
        m = m.reshape(-1, 3)
        print(m)
        if 100:
            m = m[m[:, 2] <= 100]