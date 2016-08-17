def powersum(index):
    num = 2**index
    sum = 0
    while num > 0:
        sum += num % 10
        num //= 10
    return sum
def main():
    power = int(input("Enter Power of 2 : "))
    print("Sum of digits of 2^{0} is {1}".format(power,powersum(power)))

main()