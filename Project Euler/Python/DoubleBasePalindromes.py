def is_palindrome(num):
    if str(num) == (str(num)[::-1]):
        return True
    else:
        return False
def to_binary(num):
    bin = ""
    while num != 0:
        bin += str(num % 2)
        num //= 2
    return bin[::-1]
sum = 0
for i in range(1,1000000):
    if is_palindrome(i) and is_palindrome(to_binary(i)):
        sum += i
        print(i)
print(sum)