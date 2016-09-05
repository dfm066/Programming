def gridSum(arr):
    max = 0
    nos = []
    for i in range(0, 20):
        tmp1 = 0
        tmp2 = 0
        tmp3 = 0
        tmp4 = 0
        for j in range(0, 20):
            if (j < 17) and (i < 17):
                tmp1 = arr[i][j] * arr[i][j + 1] * arr[i][j + 2] * arr[i][j + 3]
                tmp2 = arr[i][j] * arr[i + 1][j + 1] * arr[i + 2][j + 2] * arr[i + 3][j + 3]
                tmp3 = arr[i][j] * arr[i + 1][j] * arr[i + 2][j] * arr[i + 3][j]
            elif (i < 17):
                tmp3 = arr[i][j] * arr[i + 1][j] * arr[i + 2][j] * arr[i + 3][j]
            elif (j < 17):
                tmp1 = arr[i][j] * arr[i][j + 1] * arr[i][j + 2] * arr[i][j + 3]
            if (j > 2) and (i < 17):
                tmp4 = arr[i][j] * arr[i + 1][j - 1] * arr[i + 2][j - 2] * arr[i + 3][j - 3]
            if (tmp1 > max):
                nos.clear()
                max = tmp1
                nos.append([arr[i][j], arr[i][j + 1], arr[i][j + 2], arr[i][j + 3]])
            if (tmp2 > max):
                nos.clear()
                max = tmp2
                nos.append([arr[i][j], arr[i + 1][j + 1], arr[i + 2][j + 2], arr[i + 3][j + 3]])
            if (tmp3 > max):
                nos.clear()
                max = tmp3
                nos.append([arr[i][j], arr[i + 1][j], arr[i + 2][j], arr[i + 3][j]])
            if (tmp4 > max):
                nos.clear()
                max = tmp4
                nos.append([arr[i][j], arr[i + 1][j - 1], arr[i + 2][j - 2], arr[i + 3][j - 3]])
    print(nos)
    return max


def main():
    arr = []
    for i in range(20):
        temp = [int(i) for i in input().split()]
        arr.append(temp)
    print(gridSum(arr))


main()
