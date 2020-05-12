import math

def p91(lower, upper) -> int:
    # right angle at origin
    tcount = (upper-lower)*(upper-lower)
    for x1 in range(lower, upper+1):
        for y1 in range(lower, upper+1):
                
            for x2 in range(lower, upper+1):
                for y2 in range(lower, upper+1):
                    # non-zero surface and right angle at x1,y1 using dot product
                    if x1*y2 - x2*y1 != 0 and x1*(x2-x1) + y1*(y2-y1) == 0:
                        tcount += 1
    return tcount


print(p91(0, 50))

