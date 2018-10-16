def next_permutation(arr):
    # Find non-increasing suffix
    i = len(arr) - 1
    while i > 0 and arr[i - 1] >= arr[i]:
        i -= 1
    if i <= 0:
        return False

    # Find successor to pivot
    j = len(arr) - 1
    while arr[j] <= arr[i - 1]:
        j -= 1
    arr[i - 1], arr[j] = arr[j], arr[i - 1]

    # Reverse suffix
    arr[i:] = arr[len(arr) - 1: i - 1: -1]


permutations = []
s = 'abcdefghijklm'
limit = 6227020800
permutations.append(s)
for i in range(limit):
    s = next_permutation(s)
    permutations.append(s)
t = int(input())
while t > 0:
    t -= 1
    n = int(intput())
    print(permutations[n - 1])


