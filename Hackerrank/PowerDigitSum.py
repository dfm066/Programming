limit = 10000
power_sum = [1]
def build_powersum():
    index = 1
    val = 1
    while index <= limit:
        val *= 2
        power_sum.append(sum([int(i) for i in str(val)]))
        index += 1
def main():
    build_powersum()
    t = int(input())
    while t > 0:
        t -= 1
        print(power_sum[int(input())])
main()