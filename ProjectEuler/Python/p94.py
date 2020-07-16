
def p94(limit) -> int:
    sumOfPerimeters = 0
    a = 5
    b = 5
    c = 6
    p = a+b+c
    a = 0.25*((4*a*a-c*c)*(c**2))**0.5
    if (a == int(a)):
        sumOfPerimeters += p
    return sumOfPerimeters


print(p94(1000000000))

# let c be the length of non-equal side
# then length of equal sides can be c+1 or c-1
# then perimeter p = 3c+2 or 3c-2
# area A = 0.25c√(2c+2)(3c+2) or 0.25c√(2c-2)(3c-2)
# inner eq will be 6c^2+10c+4 or 6c^2-10c+4
# let G = 4+some value such that 6c^2+10c+4 or 6c^2-10c+4 is perfect square
# then 6c^2+10c+G = 0 and 6c^2-10c+G` = 0
# c = (-10 + √(100-24G))/12 or (-10 - √(100-24G))/12
# or c = (10 + √(100-24G`))/12 or (10 + √(100-24G`))/12

