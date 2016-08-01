import math
def divisor(n) -> int:

def main():
    q = int(input())
    for i in range(0,q):
        a = int(input())
        n = a
        max = divisor(a)
        for i in range(1,a):
            cnt = divisor(i)
            if max <= cnt:
                n = i
                max = cnt
        # print("Current max : {0}".format(max))
        if n == a:
            print(n)
            continue
        else:
            n = a+1

        while True:
            if max < divisor(n):
                break
            else:
                n += 1
        print(n)
main()
