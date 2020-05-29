def Solution(num):
    sum = num**2*(num+1)**2*0.25
    squareSum = num*(num+1)*(2*num+1)/6
    return sum-squareSum

print(Solution(100))