mod = 1000000007
limit = 500
list = [[0 for i in range(limit+1)] for i in range(limit+1)]
for i in range(limit+1):
    list[0][i] = list[i][0] = 1
def build_lattice_path():
    for i in range(1,limit+1):
        for j in range(1,limit+1):
            list[i][j]  = (list[i-1][j] + list[i][j-1]) % mod
def main():
    build_lattice_path()
    t = int(input())
    while t > 0:
        t -= 1
        size = [int(i) for i in input().split()]
        print(list[size[0]][size[1]])

main()

