import math
def solution(N, M):
    return int(N / math.gcd(N,M))

print(solution(3**9 * 2**14, 2**14 * 2**14))