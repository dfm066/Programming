def factorial(num):
    fact = 1
    for i in range(2,num+1):
        fact *= i
    return fact

def sumofdigit(num):
    string = str(num)
    sum = 0
    for i in string:
        sum += int(i)
    return sum

def main():
    num = int(input("Enter No : "))
    print("Sum of digit of {0}! = {1}".format(num,sumofdigit(factorial(num))))

main()