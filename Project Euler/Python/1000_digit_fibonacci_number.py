def fibonacci(n):
    if n == 0:
        return (0, 1)
    else:
        a, b = fibonacci(n // 2)
        c = a * (b * 2 - a)
        d = a * a + b * b
        if n % 2 == 0:
            return (c, d)
        else:
            return (d, c + d)
x = 0
y = 0
num = 1
while len(str(x)) < 1000:
    x, y = fibonacci(num)
    num += 1

print(len(str(y)),len(str(x)),num)