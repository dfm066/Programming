def findD(num):
    g = num//3
    if num%3!=0:
        g += 1
    if num % 3 == 1 or num %3 == 0:
        return 1
    else:
        return 2*g
def sumofdigit(num):
    string = str(num)
    sum = 0
    for i in string:
        sum += int(i)
    return sum

def main():
    n = int(input())
    numerator =[]
    denominator = [1]
    for i in range(1,n):
        denominator.append(findD(i))
    # print(denominator)
    numerator.append(denominator[-1])
    denominator.append(1)
    for i in range(n-1,1,-1):
        numerator.append(denominator[i+1]+denominator[i-1]*numerator[-1])
        denominator[i-1]=numerator[-1]
    # print(denominator)
    # print(numerator)
    if(n>1):
        N = 2*denominator[1]+denominator[2]
    else:
        N = 2
    print(N)
    print(sumofdigit(N))
main()