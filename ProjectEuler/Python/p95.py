from utils import utils

def p95(limit):
    div_sum = [1]*(limit+1)
    div_sum[0] = div_sum[1] = 0
    for d in range(2, limit+1):
        m = 2
        n = d*m
        while n <= limit:
            div_sum[n] += d
            m += 1
            n = d*m
    max_len = 0
    smallest = 0
    visited = [False] * (limit+1)
    chain = [0] * (limit+1)
    for i in range(limit+1):
        chain[i] = [i]
    for n in range(0, 4):
        visited[n] = True
        chain[n] = [n//2]

    plotter = utils()
    plotter.plot_graph("Amicable numbers", range(limit+1), div_sum, "Number", "Divisor sum")
    # for n in range(4, limit+1):
    #     if visited[n]:
    #         if chain[n][0] == chain[n][-1]:
    #             continue
    #         ptr = chain[n][-1]
    #         cnt = len(chain[n])
    #     else :
    #         visited[n] = True
    #         ptr = n
    #         cnt = 0
    #     while ptr < limit+1 and ptr > 2:
    #         nxtptr = div_sum[ptr]
    #         if nxtptr > limit or nxtptr < 1:
    #             break
    #         if nxtptr < n:
    #             chain[n].extend(chain[nxtptr])
    #             break
    #         chain[n].append(nxtptr)
    #         cnt += 1
    #         if ptr == nxtptr:
    #             break
    #         ptr = nxtptr
    #         if ptr == n:
    #             break
    #     update_chain = []
        # for i in range(1, len(chain[n])):
        #     if chain[n][i] == n:
        #         break
        #     for v in update_chain:
        #         if chain[v][-1] == chain[n][i]:
        #             continue
        #         chain[v].append(chain[n][i])
        #         visited[v] = True
        #     update_chain.append(chain[n][i])

    for c in chain:
        if len(c) > 1 and c[0] == c[-1] and len(c) > max_len:
            max_len = len(c)
            smallest = c[0]

    # print(chain)
    return smallest

print(p95(100))